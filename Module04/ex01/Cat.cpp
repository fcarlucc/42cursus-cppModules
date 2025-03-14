#include "Cat.hpp"

Cat::Cat(): Animal() {
	this->brain = new Brain();
	this->setType("Cat");
	std::cout << "Cat constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat&	Cat::operator=(const Cat &other) {
	if (this == &other)
		return *this;
	this->setType(other.getType());
	return *this;
}

std::string Cat::getType() const {
	return this->type;
}

void	Cat::setType(std::string type) {
	this->type = type;
	return ;
}

Brain*	Cat::getBrain() const {
	return this->brain;
}

void	Cat::makeSound() const {
	std::cout << "Miao !" << std::endl;
}
