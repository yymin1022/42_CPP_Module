#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat& obj): Animal(obj){
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*obj.brain);
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat& obj){
	if(this != &obj){
		delete this->brain;
		this->brain = new Brain(*obj.brain);
		this->type = obj.type;
	}

	return *this;
}

void Cat::makeSound() const{
	std::cout << "I am a Cat! I am a Cat!" << std::endl;
}
