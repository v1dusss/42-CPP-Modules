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

	return 0;
}