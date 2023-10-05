#include "Fixed.hpp"

Fixed::Fixed(): _fixed_point_nb(0)
{
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::Fixed(Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		_fixed_point_nb = other._fixed_point_nb;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point_nb);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point_nb = raw;
}