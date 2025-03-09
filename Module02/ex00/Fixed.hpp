#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>

class Fixed {

	private:
		int					fpn;
		static const int	fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed &toCopy);
		~Fixed();
		Fixed&	operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif