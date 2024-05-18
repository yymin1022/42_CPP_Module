#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called" << "\n";
}

Brain::Brain(const Brain& obj){
	std::cout << "Brain copy constructor called" << "\n";
	*this = obj;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << "\n";
}

Brain& Brain::operator=(const Brain& obj){
	if(this != &obj){
		for(int i = 0; i < 100; i++){
			(this->ideas)[i] = obj.ideas[i];
		}
	}

	return *this;
}
