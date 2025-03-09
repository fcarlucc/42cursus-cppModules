#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	//std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &toCopy) : AMateria(toCopy) {}

Ice &Ice::operator=(const Ice &other) {

	if (this != &other)
		this->type = other.type;
	return *this;
}

Ice::~Ice() {
	//std::cout << "Ice destructor called" << std::endl;
}

// pure function implementation in Ice
Ice *Ice::clone() const {

	Ice *tmp = new Ice();

	if (tmp != NULL)
		return tmp;
	else
		return NULL;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
