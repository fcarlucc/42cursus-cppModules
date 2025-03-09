#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)  : name(name) ,hitPoints(100), energyPoints(50), attackDamage(20) {
	std::cout << "Constructor of ClapTrap " << this->name << " called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy) {
	*this = toCopy;
	return ;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor of ClapTrap " << this->name << " called" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " cannot attack, insufficient hit points or energy." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints -= 1;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	if (hitPoints < 0) {
		hitPoints = 0;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Hit points now at " << hitPoints << "." << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " cannot repair, insufficient hit points or energy." << std::endl;
		return ;
	}
	hitPoints += amount;
	energyPoints -= 1;
	std::cout << "ClapTrap " << name << " is repaired for " << amount << " points! Hit points now at " << hitPoints << "." << std::endl;
	return ;
}

void ClapTrap::setName(const std::string name) {
	this->name = name;
}

void ClapTrap::setHitPoints(int hitPoints) {
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
	this->attackDamage = attackDamage;
}

std::string ClapTrap::getName() const {
	return name;
}

int ClapTrap::getHitPoints() const {
	return hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return attackDamage;
}
