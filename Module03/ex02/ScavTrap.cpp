#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Constructor of ScavTrap " << this->getName() << " called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &toCopy): ClapTrap(toCopy) {
	*this = toCopy;
	return ;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor of ScavTrap " << this->getName() << " called" << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " is now in gate keeper mode" << std::endl;
}
