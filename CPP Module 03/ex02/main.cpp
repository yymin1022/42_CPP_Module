#include "FragTrap.hpp"

int main(){
	FragTrap fragtrap1("Fragtrap");
	FragTrap fragtrap2(fragtrap1);
	FragTrap fragtrap3;
	fragtrap3 = fragtrap1;

	fragtrap1.attack("target");
	fragtrap1.takeDamage(5);
	fragtrap1.beRepaired(5);
	fragtrap1.highFivesGuys();

	return 0;
}
