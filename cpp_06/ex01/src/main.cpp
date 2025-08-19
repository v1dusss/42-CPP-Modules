#include <iostream>
#include "Serializer.hpp"

int main() {
	Data d{42, "example", 3.14};

	Data* original = &d;
	uintptr_t raw  = Serializer::serialize(original);
	Data* roundtrip = Serializer::deserialize(raw);

	std::cout << "Original pointer : " <<  BOLD BLUE << original  << RESET << "\n";
	std::cout << "Serialized (hex) : " <<  BOLD BLUE << "0x" << std::hex << raw << std::dec << RESET << "\n";
	std::cout << "Deserialized ptr : " <<  BOLD BLUE << roundtrip << RESET << "\n\n";

	if (roundtrip == original) {
		std::cout << BOLD GREEN << "Success: pointers match.\n" << RESET;
	} else {
		std::cerr << BOLD RED << "Failure: pointers do not match.\n" << RESET;
	}

	std::cout << "Data check -> id: " << roundtrip->id
			  << ", name: " << roundtrip->name
			  << ", value: " << roundtrip->value << "\n";
}