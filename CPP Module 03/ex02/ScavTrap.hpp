#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& obj);
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& obj);

	void beRepaired(unsigned int amount);
	void guardGate();
};

#endif
