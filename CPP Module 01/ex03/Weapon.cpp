#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type): type(type){}

Weapon::~Weapon(){}

const std::string& Weapon::getType() const{
	return type;
}

void Weapon::setType(std::string type){
	this->type = type;
}
