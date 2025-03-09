#include "HumanB.hpp"

void HumanB::attack() const {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	return ;
}

HumanB::HumanB() {}

HumanB::HumanB(std::string s) : name(s) {}

HumanB::~HumanB() {}

std::string HumanB::getName() const {
	return name;
}

void HumanB::setName(std::string newName) {
	name = newName;
}

Weapon* HumanB::getWeapon() const {
	return weapon;
}

void HumanB::setWeapon(Weapon& newWeapon) {
	weapon = &newWeapon;
}
