#ifndef WRONGWrongCAT_HPP
#define WRONGWrongCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const WrongCat &toCopy);
		~WrongCat();
		WrongCat&	operator=(const WrongCat &other);
		std::string getType() const;
		void		setType(std::string type);
		void		makeSound(void) const;
};

#endif
