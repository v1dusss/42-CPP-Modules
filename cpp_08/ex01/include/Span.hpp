#pragma once

#include <algorithm>
#include <stdexcept>
#include <deque>

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

class Span {
    private:
        Span() = delete;
        unsigned int _maxSize;
        std::deque<int> _array;

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span() = default;

        void addNumber(int number);
        int shortSpan() const;
        int longSpan() const;
};