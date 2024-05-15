#include "Fixed.hpp"

Fixed::Fixed(): value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
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
