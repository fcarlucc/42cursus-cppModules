#include "Dog.hpp"

Dog::Dog(): Animal() {
	this->brain = new Brain();
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
	delete this->brain;
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

Brain*	Dog::getBrain() const {
	return this->brain;
}

void	Dog::makeSound() const {
	std::cout << "Bau !" << std::endl;
}
