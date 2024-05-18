#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("ClapTrap"), hit_points(10), energy_points(10), attack_damage(0), max_hp(10){
    std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj){
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj){
    if (this != &obj){
        this->name = obj.name;
        this->hit_points = obj.hit_points;
        this->energy_points = obj.energy_points;
        this->attack_damage = obj.attack_damage;
		this->max_hp = obj.max_hp;
    }

    return *this;
}

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0), max_hp(10){
    std::cout << "ClapTrap constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy_points > 0)
    {
        (this->energy_points)--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
    }else{
        std::cout << "ClapTrap " << this->name << " has no energy points!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points > 0){
		if (amount > hit_points){
			amount = hit_points;
		}
        this->hit_points -= amount;
        std::cout << this->name << " takes damage! " << this->hit_points << " hit points left." << std::endl;
    }else{
        std::cout << this->name << " is already dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if(this->energy_points == 0){
		std::cout << this->name << " has no energy points!" << std::endl;
	}else if(this->hit_points == this->max_hp){
		std::cout << this->name << " is already full hit points!" << std::endl;
	}else{
		if(amount > this->max_hp){
			amount = this->max_hp;
		}
		if(amount + this->hit_points > this->max_hp){
			amount = this->max_hp - this->hit_points;
			this->hit_points = this->max_hp;
		}else{
			this->hit_points += amount;
		}
		(this->energy_points)--;
		std::cout << this->name << " is repaired! Now hit points is full! " << this->energy_points << " energy points left." << std::endl;
	}
}
