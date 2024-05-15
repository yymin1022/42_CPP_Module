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
	Fixed operator+(const Fixed& obj) const;
	Fixed operator-(const Fixed& obj) const;
	Fixed operator*(const Fixed& obj) const;
	Fixed operator/(const Fixed& obj) const;
	bool operator>(const Fixed& obj) const;
	bool operator<(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int getRawBits() const;
	void setRawBits(int const raw);
	int toInt() const;
	float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
