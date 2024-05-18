#include "Cat.hpp"

Cat::Cat(){
	type = "Cat";
	std::cout << "Cat default constructor called" << "\n";
}

Cat::Cat(const Cat& obj): Animal(obj){
	std::cout << "Cat copy constructor called" << "\n";
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << "\n";
}

Cat& Cat::operator=(const Cat& obj){
	if(this != &obj)
		type = obj.type;

	return *this;
}

void Cat::makeSound() const{
	std::cout << "I am a Cat! I am a Cat!" << "\n";
}
