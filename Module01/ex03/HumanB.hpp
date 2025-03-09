#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {

	private:

		std::string	name;
		Weapon*		weapon;

	public:

		void attack() const;

		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);

		std::string getName() const;
		void setName(std::string name);
		Weapon* getWeapon() const;
		void setWeapon(Weapon& weapon);
};

#endif
