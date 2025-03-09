#include "Character.hpp"

Character::Character() {

	// std::cout << "Character constructor called" << std::endl;
	this->name = "";
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++) {
		this->tmp[i] = NULL;
	}
}

Character::Character(const Character &toCopy) {

	// std::cout << "Character copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

Character	&Character::operator=(const Character &rhs) {

	if (this != &rhs) {
		this->name = rhs.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = rhs.inventory[i];
		}
		for (int i = 0; i < 100; i++) {
			if (this->tmp[i])
				delete this->tmp[i];
			this->tmp[i] = rhs.tmp[i];
		}
	}
	return *this;
}

Character::~Character() {
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	for (int i = 0; i < 100; i++) {
		if (this->tmp[i] != NULL)
			delete this->tmp[i];
	}
}

Character::Character(std::string name) : name(name) {
	//std::cout << "Character constructed with " << name << " name and empty inventory!" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++) {
		this->tmp[i] = NULL;
	}
}

std::string const &Character::getCharacterAMateriaType(int idx) const
{
	return inventory[idx]->getType();
}

// ICharacter methods
std::string const &Character::getName() const {
	return name;
}

void	Character::equip(AMateria *m) {
	if (m == NULL) {
		std::cerr << "No materia to equip " << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i ++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			std::cout << "Materia " << m->getType() << " equipped in slot " << i << std::endl;
			return;
		}
	}
	std::cerr << "full inventory, cannot equip!" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx >= 4 || idx <= -1) {
		std::cerr << "Wrong index of Materia" << std::endl;
		return ;
	}
	static int j = 0;
	if (this->inventory[idx]) {
		std::cout << "Character " << this->getName() << " unequip " << this->getCharacterAMateriaType(idx) << " on slot " << idx << std::endl;
		this->tmp[j] = this->inventory[idx];
		j++;
		this->inventory[idx] = NULL;
	}
	else
		std::cerr << "cannot unequip" << std::endl;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx >= 4 || idx <= -1) {
		std::cerr << "Wrong index of Materia" << std::endl;
		return ;
	}
	else if (this->inventory[idx])
		this->inventory[idx]->use(target);
	else
	{
		std::cerr << "cannot use" << std::endl;
		return ;
	}
}
