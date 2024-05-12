#include "Zombie.hpp"

Zombie* zombieHorde(int cnt, std::string name){
	Zombie *zombies = new Zombie[cnt];

	for(int i = 0; i < cnt; i++){
		zombies[i].setName(name);
	}

	return (zombies);
}
