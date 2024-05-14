#include "Fixed.hpp"

Fixed::Fixed(): value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(int const value){
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bits;
}

Fixed::Fixed(float const value){
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bits));
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj){
	std::cout << "Copy assignment operator called" << std::endl;

	if(this != &obj)
		value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;

	return value;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;

	this->value = raw;
}

int Fixed::toInt() const{
	return value >> bits;
}

float Fixed::toFloat() const{
	return static_cast<float>(value) / (1 << bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj){
	os << obj.toFloat();
	return os;
}
