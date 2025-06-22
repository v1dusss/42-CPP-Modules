#pragma once

#include <stack>
#include <iostream>

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other) {
                std::stack<T>::operator=(other);
            }
            return *this;
        }
        ~MutantStack() = default;

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }
};