#include "ClapTrap.hpp"

int main(){
	ClapTrap claptrap1("Claptrap");

	claptrap1.attack("target");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(5);

	return 0;
}
