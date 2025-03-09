#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal {

	private:
		Brain	*brain;

	public:
		Cat();
		Cat(const Cat &toCopy);
		~Cat();
		Cat&		operator=(const Cat &other);
		std::string	getType() const;
		Brain*		getBrain() const;
		void		setType(std::string type);
		void		makeSound(void) const;
};

#endif
