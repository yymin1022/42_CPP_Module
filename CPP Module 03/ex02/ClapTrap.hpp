#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
protected:
	std::string name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap& obj);
	ClapTrap(std::string name);
	virtual ~ClapTrap();
	ClapTrap& operator=(const ClapTrap& obj);

	void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
};

#endif
