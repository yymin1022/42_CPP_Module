#include "FragTrap.hpp"

int main(){
	FragTrap fragtrap1("Fragtrap");

	fragtrap1.attack("target");
	fragtrap1.takeDamage(5);
	fragtrap1.beRepaired(5);
	fragtrap1.highFivesGuys();

	return 0;
}
