#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {

	Zombie* zombies = new Zombie[n];

	for (int i = 0; i < n; i++) {
		std::ostringstream oss;
		oss << (i + 1);
		zombies[i].setName(name + oss.str());
		zombies[i].announce();
	}
	return zombies;
}
