#include "DiamondTrap.hpp"

int main() {

	DiamondTrap diamond("Diamond");

	diamond.attack("target");
	diamond.takeDamage(10);
	diamond.beRepaired(5);
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();

	return 0;
}

