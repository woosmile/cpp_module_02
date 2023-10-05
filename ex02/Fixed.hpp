#ifndef FIXED_HPP
# define FIXED_HPP
 
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixed_point_nb;
		static const int	_fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &other);
		~Fixed();
		Fixed&				operator=(const Fixed &other);
		bool				operator>(const Fixed &other);
		bool				operator<(const Fixed &other);
		bool				operator>=(const Fixed &other);
		bool				operator<=(const Fixed &other);
		bool				operator==(const Fixed &other);
		bool				operator!=(const Fixed &other);
		Fixed&				operator+(const Fixed &other);
		Fixed&				operator-(const Fixed &other);
		Fixed&				operator*(const Fixed &other);
		Fixed&				operator/(const Fixed &other);
		Fixed&				operator++();
		Fixed				operator++(int);
		Fixed&				operator--();
		Fixed				operator--(int);
		void 				setRawBits(int const raw);
		int					getRawBits(void) const;
		int					toInt(void) const;
		float				toFloat(void) const;
		static Fixed&		min(Fixed &left, Fixed &right);
		static const Fixed&	min(const Fixed &left, const Fixed &right);
		static Fixed&		max(Fixed &left, Fixed &right);
		static const Fixed&	max(const Fixed &left, const Fixed &right);
};

std::ostream& operator<<(std::ostream &out, const Fixed &t);

#endif