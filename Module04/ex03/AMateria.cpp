#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "Amateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
	std::cout << "Amateria constructor with " << this->type << " type" << std::endl;
}

AMateria::AMateria(const AMateria &toCopy) {
	std::cout << "Amateria copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

AMateria::~AMateria() {
	std::cout << "Amateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	std::cout << "Amateria copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

std::string const &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter &target) {
	(void)target; // non puo essere instanziato
}
