#include "ScavTrap.hpp"

int main(){
	ScavTrap scavtrap1("Scavtrap");
	ScavTrap scavtrap2(scavtrap1);
	ScavTrap scavtrap3;
	scavtrap3 = scavtrap1;

	scavtrap1.attack("target");
	scavtrap1.takeDamage(5);
	scavtrap1.beRepaired(5);
	scavtrap1.guardGate();

	return 0;
}
