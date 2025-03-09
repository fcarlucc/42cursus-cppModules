#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->materiaSourceInventory[i] = NULL;
	}
	return ;
}

MateriaSource::MateriaSource(MateriaSource &toCopy) {
	*this = toCopy;
	return ;
}

MateriaSource &MateriaSource::operator=(MateriaSource &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (this->materiaSourceInventory[i])
				delete materiaSourceInventory[i];
			materiaSourceInventory[i] = rhs.materiaSourceInventory[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {

	for (int i = 0; i < 4; i++) {
		if (this->materiaSourceInventory[i] != NULL)
			delete materiaSourceInventory[i];
	}
	return ;
}

void MateriaSource::learnMateria(AMateria *mat) {

	if (mat == NULL) {
		std::cerr << "cannot learn no Materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->materiaSourceInventory[i] == NULL) {
			this->materiaSourceInventory[i] = mat;
			return;
		}
	}
	std::cerr << "cannot learn a Materia" << std::endl;
	return ;
}

AMateria *MateriaSource::createMateria(std::string const &type) {

	if (type == "ice" || type == "cure") {
		for (int i = 0; i < 4; ++i) {
			if (this->materiaSourceInventory[i] != NULL) {
				if (this->materiaSourceInventory[i] != NULL && this->materiaSourceInventory[i]->getType() == type)
					return this->materiaSourceInventory[i]->clone();
			}
		}
		std::cerr << "cannot create Materia" << std::endl;
		return NULL;
	} else {
		std::cerr << "wrong type of Materia" << std::endl;
		return NULL;
	}
}
