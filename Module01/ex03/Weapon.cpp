#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string s) : type(s) {}

Weapon::~Weapon() { std::cout << type << " destroyed.\n"; }

std::string Weapon::getType() const {
	return type;
}

void Weapon::setType(std::string newType) {
	type =  newType;
}
