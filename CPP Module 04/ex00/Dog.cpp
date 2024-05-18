#include "Dog.hpp"

Dog::Dog(){
	type = "Dog";
	std::cout << "Dog default constructor called" << "\n";
}

Dog::Dog(const Dog& obj): Animal(obj){
	std::cout << "Dog copy constructor called" << "\n";
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << "\n";
}

Dog& Dog::operator=(const Dog& obj){
	if(this != &obj)
		type = obj.type;

	return *this;
}

void Dog::makeSound() const{
	std::cout << "I am a Dog! I am a Dog!" << "\n";
}
