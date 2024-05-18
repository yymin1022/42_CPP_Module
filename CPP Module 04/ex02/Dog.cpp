#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog& obj): Animal(obj){
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*obj.brain);
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog& Dog::operator=(const Dog& obj){
	if(this != &obj){
		delete this->brain;
		this->brain = new Brain(*obj.brain);
		this->type = obj.type;
	}

	return *this;
}

void Dog::makeSound() const{
	std::cout << "I am a Dog! I am a Dog!" << std::endl;
}
