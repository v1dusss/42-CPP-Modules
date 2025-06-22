#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    Span span(5);

    span.addNumber(6);
    span.addNumber(3);
    span.addNumber(17);
    span.addNumber(9);
    span.addNumber(11);
    span.addNumber(5);
    try {
        std::cout << "Short span: " << span.shortSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Long span: " << span.longSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}