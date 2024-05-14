#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
private:
	static const int bits = 8;
	int value;
public:
	Fixed();
	Fixed(const Fixed& obj);
	Fixed(int const value);
	Fixed(float const value);
	~Fixed();
	Fixed& operator=(const Fixed& obj);

	int getRawBits() const;
	void setRawBits(int const raw);
	int toInt() const;
	float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
