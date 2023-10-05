#include "Fixed.hpp"

std::ostream& operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	
	return (out);
}

Fixed::Fixed(): _fixed_point_nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_nb = num << _fractional_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_nb = roundf(num * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &other)
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

void Fixed::setRawBits(int const raw)
{
	_fixed_point_nb = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_fixed_point_nb);
}

int	Fixed::toInt(void) const
{
	return (_fixed_point_nb >> _fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixed_point_nb / (1 << _fractional_bits));
}