#include "Harl.hpp"

int main(int ac, char **av) {

	if (ac != 2 || (std::strcmp(av[1], "DEBUG") && std::strcmp(av[1], "INFO") && std::strcmp(av[1], "WARNING") && std::strcmp(av[1], "ERROR")))
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	else {
		Harl harl;
		harl.complain(av[1]);
	}
	return 0;
}
