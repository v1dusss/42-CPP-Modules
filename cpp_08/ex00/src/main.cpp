#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
