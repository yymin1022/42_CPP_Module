#include "Animal.hpp"

Animal::Animal(){
	this->type = "Animal";
	std::cout << "Animal default constructor called" << "\n";
}

Animal::Animal(const Animal& obj){
	std::cout << "Animal copy constructor called" << "\n";
	*this = obj;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << "\n";
}

Animal&	Animal::operator=(const Animal& obj){
	if(this != &obj)
		type = obj.type;
		
	return *this;
}

std::string Animal::getType() const{
	return type;
}

void Animal::makeSound() const{
	std::cout << "I am an Animal! I am an Animal!" << "\n";
}
