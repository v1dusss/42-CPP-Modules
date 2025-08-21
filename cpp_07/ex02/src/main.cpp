#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << BOLD BLUE << "=== Array Template Test ===" << RESET << std::endl;

    try {
        // Test 1: Default constructor (empty array)
        std::cout << "\n" << YELLOW BOLD << "1. Testing default constructor:" << RESET << std::endl;
        Array<int> emptyArray;
        std::cout << GREEN << "Empty array size: " << emptyArray.size() << RESET << std::endl;

        // Test 2: Constructor with parameter
        std::cout << "\n" << YELLOW BOLD << "2. Testing constructor with parameter:" << RESET << std::endl;
        Array<int> intArray(5);
        std::cout << GREEN << "Int array size: " << intArray.size() << RESET << std::endl;

        // Test 3: Initialize elements and display
        std::cout << "\n" << YELLOW BOLD << "3. Initializing and displaying elements:" << RESET << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << BLUE << "intArray[" << i << "] = " << intArray[i] << RESET << std::endl;
        }

        // Test 4: Copy constructor
        std::cout << "\n" << YELLOW BOLD << "4. Testing copy constructor:" << RESET << std::endl;
        Array<int> copyArray(intArray);
        std::cout << GREEN << "Copy array size: " << copyArray.size() << RESET << std::endl;

        // Modify original to test deep copy
        intArray[0] = 999;
        std::cout << MAGENTA << "After modifying original array:" << RESET << std::endl;
        std::cout << RED << "Original[0] = " << intArray[0] << RESET << std::endl;
        std::cout << GREEN << "Copy[0] = " << copyArray[0] << " (should be 0, not 999)" << RESET << std::endl;

        // Test 5: Assignment operator
        std::cout << "\n" << YELLOW BOLD << "5. Testing assignment operator:" << RESET << std::endl;
        Array<int> assignArray;
        assignArray = copyArray;
        std::cout << GREEN << "Assigned array size: " << assignArray.size() << RESET << std::endl;
        std::cout << BLUE << "Assigned[1] = " << assignArray[1] << RESET << std::endl;

        // Test 6: String array
        std::cout << "\n" << YELLOW BOLD << "6. Testing with string array:" << RESET << std::endl;
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "!";

        for (unsigned int i = 0; i < stringArray.size(); i++) {
            std::cout << CYAN << "stringArray[" << i << "] = \"" << stringArray[i] << "\"" << RESET << std::endl;
        }

        // Test 7: Testing the tip from the exercise
        std::cout << "\n" << YELLOW BOLD << "7. Testing the tip: int * a = new int(); then display *a:" << RESET << std::endl;
        int * a = new int();
        std::cout << MAGENTA << "*a = " << *a << " (default initialized)" << RESET << std::endl;
        delete a;

        // Test 8: Out of bounds access (should throw exception)
        std::cout << "\n" << YELLOW BOLD << "8. Testing out of bounds access:" << RESET << std::endl;
        try {
            std::cout << BLUE << "Trying to access index 10 in array of size 5..." << RESET << std::endl;
            std::cout << intArray[10] << std::endl;
        } catch (const std::exception& e) {
            std::cout << GREEN BOLD << "✓ Exception caught: Out of bounds access detected!" << RESET << std::endl;
        }

        // Test 9: Empty array access (should throw exception)
        std::cout << "\n" << YELLOW BOLD << "9. Testing empty array access:" << RESET << std::endl;
        try {
            std::cout << BLUE << "Trying to access index 0 in empty array..." << RESET << std::endl;
            std::cout << emptyArray[0] << std::endl;
        } catch (const std::exception& e) {
            std::cout << GREEN BOLD << "✓ Exception caught: Empty array access detected!" << RESET << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << RED BOLD << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}