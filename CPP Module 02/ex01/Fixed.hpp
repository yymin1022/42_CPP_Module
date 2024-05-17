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
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed& operator=(const Fixed& obj);

	int getRawBits() const;
	void setRawBits(const int raw);
	int toInt() const;
	float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif