#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << BOLD RED << "Error: could not open file." << RESET << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    // Load the exchange rates database
    if (!exchange.loadExchangeRates("data.csv")) {
        std::cerr << BOLD RED << "Error: could not load exchange rates database." << RESET << std::endl;
        return 1;
    }

    exchange.processInput(argv[1]);

    return 0;
}