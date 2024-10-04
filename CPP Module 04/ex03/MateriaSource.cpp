#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& obj){
	for(int i = 0; i < 4; i++){
		if (obj._inventory[i])
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj){
	if (this != &obj){
		for (int i = 0; i < 4; i++){
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

void MateriaSource::learnMateria(AMateria* m){
	bool learned = false;
	for (int i = 0; i < 4; i++){
		if (!_inventory[i]){
			_inventory[i] = m;
			learned = true;
			break;
		}
	}

	if (!learned){
		std::cout << "Inventory is full" << "\n";
		delete m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return 0;
}
