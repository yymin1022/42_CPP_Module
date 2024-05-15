#include "Fixed.hpp"

Fixed::Fixed(): value(0){}

Fixed::Fixed(const Fixed& obj){
	*this = obj;
}

Fixed::Fixed(int const value){
	this->value = value << this->bits;
}

Fixed::Fixed(float const value){
	this->value = roundf(value * (1 << this->bits));
}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed& obj){
	if(this != &obj)
		this->value = obj.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& obj) const{
	return this->value > obj.getRawBits();
}

bool Fixed::operator<(const Fixed& obj) const{
	return this->value < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed& obj) const{
	return this->value >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed& obj) const{
	return this->value <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed& obj) const{
	return this->value == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed& obj) const{
	return this->value != obj.getRawBits();
}

Fixed Fixed::operator+(const Fixed& obj) const{
	return Fixed(toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed& obj) const{
	return Fixed(toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj) const{
	return Fixed(toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj) const{
	return Fixed(toFloat() / obj.toFloat());
}

Fixed& Fixed::operator++(void){
	(this->value)++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed& Fixed::operator--(void){
	(this->value)--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return a > b ? a : b;
}

int Fixed::getRawBits() const{
	return this->value;
}

void Fixed::setRawBits(int const raw){
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
