#include "ScavTrap.hpp"

int main() {

	ScavTrap scavTrap("Scavvy");

	scavTrap.attack("target");
	scavTrap.takeDamage(7);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();

	return 0;
}
