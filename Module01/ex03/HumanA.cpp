#include "HumanA.hpp"

void HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
	return ;
}

HumanA::HumanA(std::string s, Weapon& w) : name(s), weapon(w) {}

HumanA::~HumanA() {}

std::string HumanA::getName() const {
	return name;
}

void HumanA::setName(std::string newName) {
	name = newName;
}

Weapon* HumanA::getWeapon() const {
	return &weapon;
}

void HumanA::setWeapon(Weapon newWeapon) {
	weapon = newWeapon;
}
