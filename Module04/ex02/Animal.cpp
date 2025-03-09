#include "Animal.hpp"

Animal::Animal(): type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &toCopy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal&	Animal::operator=(const Animal &other) {
	if (this == &other)
		return *this;
	this->setType(other.getType());
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void	Animal::setType(std::string type) {
	this->type = type;
	return ;
}

void	makeSound(void) {
	//std::cout << "Animal sound !" << std::endl;         virtual function
}
