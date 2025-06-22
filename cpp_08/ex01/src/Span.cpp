#include "Span.hpp"
#include <limits.h>


Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) :_maxSize(other._maxSize), _array(other._array) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _array = other._array;
        _maxSize = other._maxSize;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_array.size() >= _maxSize) {
        throw std::length_error( RED "Span is full" RESET );
    }
    _array.push_back(number);
}

int Span::shortSpan() const {
    if (_array.size() < 2) {
        throw std::logic_error( RED "Not enough elements to find a short span" RESET );
    }
    std::deque<int> sortedArray = _array;
    std::sort(sortedArray.begin(), sortedArray.end());
    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedArray.size(); ++i) {
        int span = sortedArray[i] - sortedArray[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longSpan() const {
    if (_array.size() < 2) {
        throw std::logic_error( RED "Not enough elements to find a long span" RESET );
    }
    auto minMax = std::minmax_element(_array.begin(), _array.end());
    return *minMax.second - *minMax.first;
}