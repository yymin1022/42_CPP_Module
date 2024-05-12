#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name){
	std::cout << "Zombie " << _name << " is born" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << _name << " is dead" << std::endl;
}

void Zombie::announce(void){
	std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
