#include "Fixed.hpp"

//toInt, toFloat로 반환하는 것을 getrawbits로 바꾸기
//값 할당하는 것을 setter로
//증감 연산자 값 자체 ++로 바꾸기, 후위 연산자의 경우에는 앞에 const (a++)++ 같은 경우 고려
//min, max 함수는 함수가 멤버변수를 바꾸지 않게하기 위해서 함수 뒤에 const

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

std::ostream& operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	
	return (out);
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_fixed_point_nb = other._fixed_point_nb;
	return (*this);
}

// operator const 확인
bool Fixed::operator>(const Fixed &other) const
{
	if (toInt() > other.toInt())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed &other) 
{
	if (toInt() < other.toInt())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed &other)
{
	if (toInt() >= other.toInt())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &other)
{
	if (toInt() <= other.toInt())
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed &other)
{
	if (toInt() == other.toInt())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &other)
{
	if (toInt() != other.toInt())
		return (true);
	else
		return (false);
}

Fixed& Fixed::operator+(const Fixed &other)
{
	_fixed_point_nb = (toFloat() + other.toFloat()) * (1 << _fractional_bits);
	
	return (*this);
}

Fixed& Fixed::operator-(const Fixed &other)
{
	_fixed_point_nb = (toFloat() - other.toFloat()) * (1 << _fractional_bits);

	return (*this);
}

Fixed& Fixed::operator*(const Fixed &other)
{
	_fixed_point_nb = (toFloat() * other.toFloat()) * (1 << _fractional_bits);

	return (*this);
}

Fixed& Fixed::operator/(const Fixed &other)
{
	_fixed_point_nb = (toFloat() / other.toFloat()) * (1 << _fractional_bits);

	return (*this);
}

Fixed& Fixed::operator++()
{
	Fixed	add((float)0.00390625);

	_fixed_point_nb = _fixed_point_nb + add.getRawBits();

	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp(*this);
	Fixed	add((float)0.00390625);

	_fixed_point_nb = _fixed_point_nb + add.getRawBits();

	return (temp);
}

Fixed& Fixed::operator--()
{
	Fixed	sub((float)0.00390625);

	_fixed_point_nb = _fixed_point_nb - sub.getRawBits();

	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp(*this);
	Fixed	sub((float)0.00390625);

	_fixed_point_nb = _fixed_point_nb - sub.getRawBits();

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
	if (left.toInt() < right.toInt())
		return (right);
	else
		return (left);
}