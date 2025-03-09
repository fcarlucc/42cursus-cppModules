#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &toCopy);
		virtual ~Animal();
		Animal&			operator=(const Animal &other);
		std::string		getType() const;
		void			setType(std::string type);
		virtual void	makeSound() const = 0;     // virtual function
};

#endif
