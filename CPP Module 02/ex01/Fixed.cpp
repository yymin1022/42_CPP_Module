#include "Fixed.hpp"

Fixed::Fixed(): value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bits));
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj){
	std::cout << "Copy assignment operator called" << std::endl;

	if(this != &obj)
		this->value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;

	return this->value;
}

void Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member function called" << std::endl;

	this->value = raw;
}

int Fixed::toInt() const{
	return this->value >> this->bits;
}

float Fixed::toFloat() const{
	return static_cast<float>(this->value) / (1 << this->bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj){
	os << obj.toFloat();
	return os;
}
