#include "Zombie.hpp"

int main(void){
	Zombie *zombie = newZombie("Zombie1");
	zombie->announce();

	randomChump("Zombie2");
	randomChump("Zombie3");

	delete zombie;

	return 0;
}
