#include "Animal.hpp"

Animal::Animal(){
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
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
	std::cout << "Animal Sound! Animal Sound!" << std::endl;
}
