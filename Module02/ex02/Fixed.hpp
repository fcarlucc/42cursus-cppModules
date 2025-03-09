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
		Fixed&				operator=(const Fixed &other);
		bool				operator>(const Fixed &other);
		bool				operator<(const Fixed &other);
		bool				operator>=(const Fixed &other);
		bool				operator<=(const Fixed &other);
		bool				operator==(const Fixed &other);
		bool				operator!=(const Fixed &other);
		Fixed				operator+(const Fixed &other);
		Fixed				operator-(const Fixed &other);
		Fixed				operator*(const Fixed &other);
		Fixed				operator/(const Fixed &other);
		Fixed				operator++(int);
		Fixed&				operator++(void);
		Fixed				operator--(int);
		Fixed&				operator--(void);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);
};

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed);

#endif