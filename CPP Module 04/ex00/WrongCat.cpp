#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
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
	std::cout << "WrongCat Sound! WrongCat Sound!" << std::endl;
}
