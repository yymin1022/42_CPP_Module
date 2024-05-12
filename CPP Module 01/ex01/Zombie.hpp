#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	void setName(std::string name);
};

Zombie*	zombieHorde(int cnt, std::string name);

#endif
