#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog& obj): Animal(obj){
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& obj){
	if(this != &obj)
		this->type = obj.type;

	return *this;
}

void Dog::makeSound() const{
	std::cout << "I am a Dog! I am a Dog!" << std::endl;
}
