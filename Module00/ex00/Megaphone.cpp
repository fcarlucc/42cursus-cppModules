#include <iostream>
#include <cstring>
#include <cctype>

int main(int ac, char **av) {

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		
	for (int i = 1; i < ac; i++) {
		for (int j = 0; j < static_cast<int>(std::strlen(av[i])) ; j++) {
			av[i][j] = std::toupper(av[i][j]);
		}
		std::cout << av[i];
	}
	std::cout << std::endl;
	return 0;
}
