#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 4) {
		std::cerr << "Usage: ./program <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename);
	if (!infile) {
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return 1;
	}

	std::ofstream outfile(filename + ".replace");
	if (!outfile) {
		std::cerr << "Error creating file" << std::endl;
		return 1;
	}

	infile.close();
	outfile.close();

	return 0;
}