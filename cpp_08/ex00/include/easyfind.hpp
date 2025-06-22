#pragma once

#include <algorithm>
#include <stdexcept>

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
typename T::iterator easyfind(T &container, int value) {
    auto it = std::find(std::begin(container), std::end(container), value);
    if (it == std::end(container)) {
        throw std::runtime_error(RED "Value not found in container" RESET);
    }
    return it;
}