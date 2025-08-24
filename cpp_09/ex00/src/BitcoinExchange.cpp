#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& dateStr) const {
    if (dateStr.length() != 10) return false;
    if (dateStr[4] != '-' || dateStr[7] != '-') return false;

    try {
        int year = std::stoi(dateStr.substr(0, 4));
        int month = std::stoi(dateStr.substr(5, 2));
        int day = std::stoi(dateStr.substr(8, 2));

        if (year < 2009 || year > 10000) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;

        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Check for leap year
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && month == 2) {
            daysInMonth[1] = 29;
        }

        if (day > daysInMonth[month - 1]) return false;

        return true;
    } catch (...) {
        return false;
    }
}

bool BitcoinExchange::loadExchangeRates(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        // Skip header line
        if (firstLine) {
            firstLine = false;
            continue;
        }

        std::istringstream iss(line); // Convert line to a stream
        std::string date, rateStr;

        if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
            try {
                if (!isValidDate(date)) {
                    std::cerr << "Error: invalid date format: " << date << std::endl;
                    continue;
                }

                double rate = std::stod(rateStr);
                if (rate < 0) {
                    std::cerr << "Error: negative exchange rate: " << rate << std::endl;
                    continue;
                }

                _exchangeRates[date] = rate;
            } catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << line << std::endl;
                continue;
            }
        }
    }

    file.close();
    return !_exchangeRates.empty();
}
