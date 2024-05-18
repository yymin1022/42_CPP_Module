#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj){
	if(this != &obj)
		this->type = obj.type;

	return *this;
}

std::string WrongAnimal::getType() const{
	return this->type;
}

void WrongAnimal::makeSound() const{
	std::cout << "I am an WrongAnimal! I am an WrongAnimal!" << std::endl;
}
