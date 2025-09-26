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

        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;

        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Check for leap year
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && month == 2) {
            daysInMonth[1] = 29;
        }

        if (day > daysInMonth[month - 1]) return false;

        if (year <= 2009 && month == 1 && day < 3) return false; // Bitcoin genesis block was mined on 2009-01-03

        return true;
    } catch (...) {
        return false;
    }
}

bool BitcoinExchange::isValidPrice(double price) const {
    if (price < 0) {
        return false;
    }
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& targetDate) const {
    std::string closestDate = "";

    for (const auto& pair : _exchangeRates) {
        if (pair.first <= targetDate) {
            if (closestDate.empty() || pair.first > closestDate) {
                closestDate = pair.first;
            }
        }
    }

    return closestDate;
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

double BitcoinExchange::getExchangeRate(const std::string &date) const {
    auto it = _exchangeRates.find(date);
    if (it != _exchangeRates.end()) {
        return it->second;
    }

    // Find closest earlier date
    std::string closestDate = findClosestDate(date);
    if (closestDate.empty()) {
        throw std::runtime_error("No earlier date found in database");
    }

    return _exchangeRates.at(closestDate);
}

double BitcoinExchange::calculateValue(const std::string &date, double amount) const {
    if (!isValidDate(date)) {
        throw std::runtime_error("bad input => " + date);
    }

    if (!isValidPrice(amount)) {
        if (amount < 0) {
            throw std::runtime_error("not a positive number.");
        } else {
            throw std::runtime_error("too large a number.");
        }
    }

    double rate = getExchangeRate(date);
    return amount * rate;
}

void BitcoinExchange::processInput(const std::string &filename) const {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        // Skip header line
        if (firstLine) {
            firstLine = false;
            continue;
        }

        // Find the pipe separator
        size_t pipePos = line.find(" | ");
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 3);

        try {
            double value = std::stod(valueStr);
            if (value < 0) {
                throw std::runtime_error("negative value => " + std::to_string(value));
            } else if (value > 1000) {
                throw std::runtime_error("too large a number => " + std::to_string(value));
            }
            double result = calculateValue(date, value);
            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    file.close();
}