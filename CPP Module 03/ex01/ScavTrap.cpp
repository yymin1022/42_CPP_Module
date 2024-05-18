#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap Default Constructor Called" << std::endl;
    this->name = "ScavTrap";
    this->attack_damage = 20;
    this->energy_points = 50;
    this->hit_points = 100;
	this->max_hp = 100;
}

ScavTrap::ScavTrap(const ScavTrap& obj): ClapTrap(){
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
		this->max_hp = obj.max_hp;
    }

    return *this;
}

ScavTrap::ScavTrap(std::string name){
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = name;
    this->attack_damage = 20;
    this->energy_points = 50;
    this->hit_points = 100;
	this->max_hp = 100;
}

void ScavTrap::attack(const std::string& target){
	if (this->energy_points > 0)
    {
        (this->energy_points)--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
    }else{
        std::cout << "ScavTrap " << this->name << " has no energy points!" << std::endl;
	}
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->name << " is in Gatekeeper mode!" << std::endl;
}
