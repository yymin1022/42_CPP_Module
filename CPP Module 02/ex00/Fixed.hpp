#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
private:
	static const int bits = 8;
	int value;
public:
	Fixed();
	Fixed(const Fixed& obj);
	~Fixed();
	Fixed& operator=(const Fixed& obj);
	int getRawBits() const;
	void setRawBits(const int raw);
};

#endif
