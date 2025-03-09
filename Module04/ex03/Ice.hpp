#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice();
		Ice(const Ice &toCopy);
		Ice &operator=(const Ice &other);
		virtual ~Ice();
		Ice* clone(void) const;
		void use(ICharacter& target);

};

#endif
