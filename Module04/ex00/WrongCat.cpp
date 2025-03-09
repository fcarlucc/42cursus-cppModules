#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->setType("WrongCat");
	std::cout << "WrongCat constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal(toCopy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat&	WrongCat::operator=(const WrongCat &other) {
	if (this == &other)
		return *this;
	this->setType(other.getType());
	return *this;
}

std::string WrongCat::getType() const {
	return this->type;
}

void	WrongCat::setType(std::string type) {
	this->type = type;
	return ;
}

void	WrongCat::makeSound() const {
	std::cout << "Wrong Miao !" << std::endl;
}
