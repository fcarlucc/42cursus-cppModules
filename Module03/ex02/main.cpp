#include "FragTrap.hpp"

int main() {

	FragTrap fragTrap("Fragger");

	fragTrap.attack("target");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(6);
	fragTrap.highFivesGuys();

	return 0;
}
