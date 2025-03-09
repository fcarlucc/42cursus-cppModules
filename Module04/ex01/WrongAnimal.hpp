#ifndef WRONGWANIMAL_HPP
#define WRONGWANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {

	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &toCopy);
		~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal &other);
		std::string		getType() const;
		void			setType(std::string type);
		void			makeSound() const;
};

#endif
