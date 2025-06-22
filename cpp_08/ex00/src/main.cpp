#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec = {10, 20, 30, 40};

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
