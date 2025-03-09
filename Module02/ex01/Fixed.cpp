#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() {

	std::cout << "Default constructor called" << std::endl;
	fpn = 0;
	return ;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	fpn = value << fractionalBits;
	return ;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	fpn = roundf(value * (1 << fractionalBits));
	return ;
}

Fixed::Fixed(const Fixed &toCopy) {

	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed &other) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

int	Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->fpn);
}

void	Fixed::setRawBits(int const raw) {

	this->fpn = raw;
	return ;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(fpn) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return fpn >> fractionalBits;
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
