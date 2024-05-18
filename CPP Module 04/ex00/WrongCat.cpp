#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj): WrongAnimal(obj){
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj){
	if(this != &obj)
		this->type = obj.type;

	return *this;
}

void WrongCat::makeSound() const{
	std::cout << "I am a WrongCat! I am a WrongCat!" << std::endl;
}
