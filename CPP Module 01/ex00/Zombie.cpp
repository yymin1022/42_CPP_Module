#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name){
	std::cout << "Zombie " << this->name << " is born" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " is dead" << std::endl;
}

void Zombie::announce(void){
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
