#include "Fixed.hpp"

Fixed::Fixed(): _fixed_point_nb(0)
{
}

Fixed::Fixed(const int num)
{
	_fixed_point_nb = num << _fractional_bits;
}

Fixed::Fixed(const float num)
{
	_fixed_point_nb = roundf(num * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{
}

void	Fixed::setRawBits(int const raw)
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

std::ostream& operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	
	return (out);
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_fixed_point_nb = other._fixed_point_nb;
	return (*this);
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (getRawBits() > other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (getRawBits() < other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (getRawBits() >= other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (getRawBits() <= other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (getRawBits() == other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (getRawBits() != other.getRawBits())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(const Fixed &other)
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other)
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other)
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other)
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++()
{
	_fixed_point_nb++;

	return (*this);
}

Fixed const	Fixed::operator++(int)
{
	Fixed	temp(*this);

	_fixed_point_nb++;

	return (temp);
}

Fixed&	Fixed::operator--()
{
	_fixed_point_nb--;

	return (*this);
}

Fixed const	Fixed::operator--(int)
{
	Fixed	temp(*this);

	_fixed_point_nb--;

	return (temp);
}

Fixed&	Fixed::min(Fixed &left, Fixed &right)
{
	if (left > right)
		return (right);
	else
		return (left);
}

const Fixed&	Fixed::min(const Fixed &left, const Fixed &right)
{
	if (left > right)
		return (right);
	else
		return (left);
}

Fixed&	Fixed::max(Fixed &left, Fixed &right)
{
	if (left < right)
		return (right);
	else
		return (left);
}

const Fixed&	Fixed::max(const Fixed &left, const Fixed &right)
{
	if (left < right)
		return (right);
	else
		return (left);
}