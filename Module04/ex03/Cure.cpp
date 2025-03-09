#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &toCopy) : AMateria(toCopy) {}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cure::~Cure() {}

Cure *Cure::clone(void) const
{
	Cure *tmp = new Cure();

	if (tmp != NULL)
		return tmp;
	else
		return NULL;
}

void Cure::use(ICharacter &target) {
	std::cout <<  "* heals " << target.getName() << "'s wounds *" << std::endl;
}
