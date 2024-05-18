#include "AAnimal.hpp"

AAnimal::AAnimal(){
	this->type = "AAnimal:";
	std::cout << "AAnimal: default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj){
	std::cout << "AAnimal: copy constructor called" << std::endl;
	*this = obj;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal: destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& obj){
	if(this != &obj)
		this->type = obj.type;

	return *this;
}

std::string AAnimal::getType() const{
	return this->type;
}

void AAnimal::makeSound() const{
	std::cout << "I am an AAnimal:! I am an AAnimal:!" << std::endl;
}
