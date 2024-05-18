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

	void attack(const std::string& target);
	void guardGate();
};

#endif
