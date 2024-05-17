#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap Default Constructor Called" << std::endl;
    this->name = "FragTrap";
    this->attack_damage = 30;
    this->energy_points = 100;
    this->hit_points = 100;
}

FragTrap::FragTrap(const FragTrap& obj){
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = obj;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj){
    if (this != &obj){
        this->name = obj.name;
        this->hit_points = obj.hit_points;
        this->energy_points = obj.energy_points;
        this->attack_damage = obj.attack_damage;
    }

    return *this;
}

FragTrap::FragTrap(std::string name){
    std::cout << "FragTrap constructor called" << std::endl;
    this->name = name;
    this->attack_damage = 30;
    this->energy_points = 100;
    this->hit_points = 100;
}

void FragTrap::beRepaired(unsigned int amount){
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

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << this->name << " requested HighFives!" << std::endl;
}
