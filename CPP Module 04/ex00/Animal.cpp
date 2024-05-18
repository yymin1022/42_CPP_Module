#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal& obj){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& obj){
	if(this != &obj)
		this->type = obj.type;

	return *this;
}

std::string Animal::getType() const{
	return this->type;
}

void Animal::makeSound() const{
	std::cout << "I am an Animal! I am an Animal!" << std::endl;
}
