#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 4) {
		std::cerr << "\033[33m" << "Usage: ./program <filename> <s1> <s2>" << "\033[0m" << std::endl;
		return 1;
	}
	
	if (argv[2][0] == '\0') {
		std::cerr << "\033[31m" << "Error: s1 cannot be empty" << "\033[0m" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename);
	if (!infile) {
		std::cerr << "\033[31m" << "Error: Cannot open file " << filename << "\033[0m" << std::endl;
		return 1;
	}

	std::ofstream outfile(filename + ".replace");
	if (!outfile) {
		std::cerr << "\033[31m" << "Error creating file" << "\033[0m" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		std::string new_line;
		while (line.find(s1) != std::string::npos)
		{
			new_line += line.substr(0, line.find(s1));
			new_line += s2;
			line = line.substr(line.find(s1) + s1.length());
		}
		new_line += line;
		outfile << new_line << std::endl;
	}

	infile.close();
	outfile.close();

	std::cout << "\033[32m" << "File " << filename << " has been successfully replaced" << "\033[0m" << std::endl;

	return 0;
}
