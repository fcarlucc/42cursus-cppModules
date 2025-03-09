#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &toCopy);
		~ScavTrap();
		ScavTrap&	operator=(const ScavTrap &other);
		void		guardGate();
};

#endif
