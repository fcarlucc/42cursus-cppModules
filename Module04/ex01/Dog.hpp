#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal {

	private:
		Brain	*brain;

	public:
		Dog();
		Dog(const Dog &toCopy);
		~Dog();
		Dog&		operator=(const Dog &other);
		std::string	getType() const;
		Brain*		getBrain() const;
		void		setType(std::string type);
		void		makeSound(void) const;
};

#endif
