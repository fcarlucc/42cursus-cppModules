#include <string>
#include <fstream>
#include <iostream>

static std::string replacing_line(std::string s, std::string word, std::string newWord) {
	size_t pos = 0;

	while ((pos = s.find(word, pos)) != std::string::npos) {
		s.replace(pos, word.length(), newWord);
	}
	return s;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Usage: " << av[0] << " <FileName> <word> <newWord>\n" << std::endl;
		return 1;
	}

	std::ifstream inFile(av[1]);
	if (!inFile.is_open()) {
		std::cerr << "Impossible to open input file: " << av[1] << std::endl;
		return 1;
	}

	std::string s = av[1];
	s += ".replace";

	std::ofstream outFile(s.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Impossible to open output file: " << s << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		line = replacing_line(line, av[2], av[3]);
		outFile << line << std::endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}
