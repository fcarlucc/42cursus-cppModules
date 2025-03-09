#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &toCopy);
		~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap &other);
		std::string		getName(void) const;
		void			setName(std::string);
		void			whoAmI();
};

#endif
