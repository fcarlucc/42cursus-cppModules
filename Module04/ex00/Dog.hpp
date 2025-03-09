#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(const Dog &toCopy);
		~Dog();
		Dog&		operator=(const Dog &other);
		std::string	getType() const;
		void		setType(std::string type);
		void		makeSound(void) const;
};

#endif
