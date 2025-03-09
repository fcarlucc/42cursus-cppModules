#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	protected:
		AMateria *materiaSourceInventory[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource &toCopy);
		MateriaSource &operator=(MateriaSource &other);
		~MateriaSource();
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};

#endif
