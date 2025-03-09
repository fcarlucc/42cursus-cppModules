#include "Zombie.hpp"

void	Zombie::announce() const {

	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}

Zombie::Zombie() {}

Zombie::Zombie(std::string s) : name(s) {}

Zombie::~Zombie() { std::cout << name << " destroyed.\n"; }

std::string Zombie::getName() const {
	return name;
}

void Zombie::setName(std::string newName) {
	name = newName;
}
