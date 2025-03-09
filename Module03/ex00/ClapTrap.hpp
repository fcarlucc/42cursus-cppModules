#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &toCopy);
		~ClapTrap();
		ClapTrap&	operator=(const ClapTrap &other);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		setName(const std::string name);
		void		setHitPoints(int hitPoints);
		void		setEnergyPoints(int energyPoints);
		void		setAttackDamage(int attackDamage);
		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAttackDamage() const;
};

#endif
