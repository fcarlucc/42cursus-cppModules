#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	
	private:
		std::string	name;
		AMateria*	inventory[4];
		AMateria*	tmp[100];

	public:
		Character();
		Character(std::string);
		Character(const Character &toCopy);
		Character &operator=(const Character &other);
		~Character();
		std::string const & getCharacterAMateriaType(int idx) const;
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
