#include "ScavTrap.hpp"

int main(){
	ScavTrap scavtrap1("Scavtrap");

	scavtrap1.attack("target");
	scavtrap1.takeDamage(5);
	scavtrap1.beRepaired(5);
	scavtrap1.guardGate();

	return 0;
}
