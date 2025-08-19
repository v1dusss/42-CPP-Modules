#pragma once

#include <cstdint>
#include "Data.hpp"

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);

    static Data* deserialize(uintptr_t raw);

    Serializer() = delete;
    Serializer(const Serializer&) = delete;
    Serializer& operator=(const Serializer&) = delete;
    ~Serializer() = delete;
};

// ANSI escape codes for color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"