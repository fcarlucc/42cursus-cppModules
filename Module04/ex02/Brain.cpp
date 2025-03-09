#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain &toCopy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain&	Brain::operator=(const Brain &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->setIdea(other.getIdea(i), i);
	return *this;
}

void	Brain::setIdea(const std::string idea, int id) {
	if (id >= 0 && id < 100)
		ideas[id] = idea;
}

std::string	Brain::getIdea(int id) const {
	if (id >= 0 && id < 100)
		return ideas[id];
	std::cout << "Error, index out of limits." << std::endl;
	return NULL;
}
