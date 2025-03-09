#include "Harl.hpp"

int main(int ac, char **av) {

	if (ac != 2 || (std::strcmp(av[1], "DEBUG") && std::strcmp(av[1], "INFO") && std::strcmp(av[1], "WARNING") && std::strcmp(av[1], "ERROR"))) {
		std::cerr << "ERROR! Usage: " << av[0] << " <DEBUG> or <INFO> or <WARNING> or <ERROR>\n";
		return 1;
	}

	Harl harl;

	harl.complain(av[1]);
	return 0;
}
