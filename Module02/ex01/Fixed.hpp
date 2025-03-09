#ifndef Fixed_HPP
#define Fixed_HPP

#include <cmath>
#include <iostream>

class Fixed {

	private:
		int					fpn;
		static const int	fractionalBits;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &toCopy);
		~Fixed();
		Fixed& 	operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream&operator<<(std::ostream &out, const Fixed &fixed);

#endif
