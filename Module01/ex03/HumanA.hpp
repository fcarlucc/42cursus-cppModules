#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {

	private:

		std::string name;
		Weapon&		weapon;

	public:

		void attack() const;
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

		std::string getName() const;
		void setName(std::string name);
		Weapon* getWeapon() const;
		void setWeapon(Weapon weapon);
};

#endif
