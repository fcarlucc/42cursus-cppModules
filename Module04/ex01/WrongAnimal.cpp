#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Wrong Animal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other) {
	if (this == &other)
		return *this;
	this->setType(other.getType());
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void	WrongAnimal::setType(std::string type) {
	this->type = type;
	return ;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Wrong Animal sound !" << std::endl;
}
