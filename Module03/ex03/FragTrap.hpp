#ifndef FRAFGTRAP_HPP
#define FRAFGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

	private:

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &toCopy);
		~FragTrap();
		FragTrap&	operator=(const FragTrap &other);
		void		highFivesGuys();
};

#endif
