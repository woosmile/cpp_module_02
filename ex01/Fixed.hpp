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
		Fixed& operator=(const Fixed &other);
		~Fixed();
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &other);

#endif