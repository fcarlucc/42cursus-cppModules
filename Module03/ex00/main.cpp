#include "ClapTrap.hpp"

int main() {

	ClapTrap clapTrap("Clappy");

	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);

	return 0;
}
