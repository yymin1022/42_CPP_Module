#include "ClapTrap.hpp"

int main(){
	ClapTrap claptrap1("Claptrap");
	ClapTrap claptrap2(claptrap1);
	ClapTrap claptrap3;
	claptrap3 = claptrap1;

	claptrap1.attack("target");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(5);

	return 0;
}
