#include "Character.hpp"

Character::Character(): _floor(0){
	for(int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& obj): _name(obj._name), _floor(obj._floor){
	for (int i = 0; i < 4; i++){
		if(obj._inventory[i])
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Character&	Character::operator=(const Character& obj){
	if (this != &obj)
	{
		_name = obj._name;
		_floor = obj._floor;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (obj._inventory[i])
				_inventory[i] = obj._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
	return *this;
}

Character::Character(std::string const & name): _name(name), _floor(0){
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

std::string const & Character::getName() const{
	return _name;
}

void Character::equip(AMateria* m){
	bool equipped = false;
	if (!m){
		std::cout << "No equipment to equip" << "\n";
		return;
	}

	for (int i = 0; i < 4; i++){
		if (!_inventory[i]){
			_inventory[i] = m;
			equipped = true;
			break;
		}
	}

	if (!equipped){
		if (!_floor){
			std::cout << "Inventory is full! Cannot drop materia on the floor! => Delete materia" << "\n";
			delete m;
			return;
		}

		_floor->dropMateria(m);
		std::cout << "Inventory is full! Drop materia on the floor" << "\n";
	}
}

void Character::unequip(int idx){
	if (!_floor){
		std::cout << "No floor to drop materia" << "\n";
		return;
	}

	if (idx >= 0 && idx < 4){
		_floor->dropMateria(_inventory[idx]);
		_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

void	Character::setFloor(Floor* floor){
	_floor = floor;
}
