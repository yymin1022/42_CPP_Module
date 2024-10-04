#include "Floor.hpp"

Floor::Floor(): _count(0){
	for (int i = 0; i < 30; i++)
		_inventory[i] = 0;
}

Floor::Floor(const Floor& obj): _count(obj._count){
	for (int i = 0; i < 30; i++){
		if (obj._inventory[i])
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Floor::~Floor(){
	for (int i = 0; i < 30; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Floor&	Floor::operator=(const Floor& obj){
	if (this != &obj){
		_count = obj._count;
		for (int i = 0; i < 30; i++){
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

void	Floor::dropMateria(AMateria* m){
	if (_inventory[_count])
		delete _inventory[_count];
	_inventory[_count] = m;
	_count = (_count + 1) % 30;
}
