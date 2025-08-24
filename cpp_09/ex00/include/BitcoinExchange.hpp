#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>

#include <chrono>
#include <iomanip>

class BitcoinExchange {
private:
    std::map<std::string, double> _exchangeRates;

    bool isValidDate(const std::string& dateStr) const;
    bool isValidPrice(double price) const;
    std::string findClosestDate(const std::string& targetDate) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool loadExchangeRates(const std::string &filename);
    double getExchangeRate(const std::string &date) const;
    double calculateValue(const std::string &date, double amount) const;
    void processInput(const std::string &filename) const;
};

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"