#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name") {
	this->setName(name);
	std::cout << "Constructor of DiamondTrap " << this->getName() << " called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &toCopy) : ClapTrap(toCopy ), FragTrap(toCopy ), ScavTrap(toCopy ) {
	*this = toCopy;
	return ;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor of DiamondTrap " << this->getName() << " called" << std::endl;
	return ;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

std::string	DiamondTrap::getName() const {
	return name;
}

void	DiamondTrap::setName(std::string name) {
	this->getName() = name;
	return ;
}

void	DiamondTrap::whoAmI() {
	std::cout << "Diamond name: " << this->getName() << std::endl;
	std::cout << "Clap name: " << ClapTrap::name << std::endl;
}
