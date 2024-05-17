#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap Default Constructor Called" << std::endl;
    this->name = "ScavTrap";
    this->attack_damage = 20;
    this->energy_points = 50;
    this->hit_points = 100;
}

ScavTrap::ScavTrap(const ScavTrap& obj){
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = obj;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj){
    if (this != &obj){
        this->name = obj.name;
        this->hit_points = obj.hit_points;
        this->energy_points = obj.energy_points;
        this->attack_damage = obj.attack_damage;
    }

    return *this;
}

ScavTrap::ScavTrap(std::string name){
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = name;
    this->attack_damage = 20;
    this->energy_points = 50;
    this->hit_points = 100;
}

void ScavTrap::beRepaired(unsigned int amount){
	if(this->energy_points == 0){
		std::cout << this->name << " has no energy points!" << std::endl;
	}else if(this->hit_points == 100){
		std::cout << this->name << " is already full hit points!" << std::endl;
	}else{
		this->hit_points += amount;
		if(this->hit_points > 100){
			this->hit_points = 100;
		}
        (this->energy_points)--;
        std::cout << this->name << " is repaired! Now hit points is full! " << this->energy_points << " energy points left." << std::endl;
    }
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->name << " is not in Gatekeeper mode!" << std::endl;
}
