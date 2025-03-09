#include "Dog.hpp"

Dog::Dog(): Animal() {
	this->setType("Dog");
	std::cout << "Dog constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &toCopy) : Animal(toCopy) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog&	Dog::operator=(const Dog &other) {
	if (this == &other)
		return *this;
	this->setType(other.getType());
	return *this;
}

std::string Dog::getType() const {
	return this->type;
}

void	Dog::setType(std::string type) {
	this->type = type;
	return ;
}

void	Dog::makeSound() const {
	std::cout << "Bau !" << std::endl;
}
