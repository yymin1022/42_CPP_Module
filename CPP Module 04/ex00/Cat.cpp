#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& obj): Animal(obj){
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj){
	if(this != &obj)
		this->type = obj.type;

	return *this;
}

void Cat::makeSound() const{
	std::cout << "I am a Cat! I am a Cat!" << std::endl;
}
