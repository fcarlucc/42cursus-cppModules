#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Constructor of FragTrap " << this->getName() << " called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &toCopy): ClapTrap(toCopy) {
	*this = toCopy;
	return ;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor of FragTrap " << this->getName() << " called" << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->getName() << " display a positive high five requests" << std::endl;
}
