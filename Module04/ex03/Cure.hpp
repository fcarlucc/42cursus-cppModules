#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure &tocopy);
		Cure &operator=(const Cure &other);
		~Cure();
		Cure* clone() const;
		void use(ICharacter& target);

};

#endif
