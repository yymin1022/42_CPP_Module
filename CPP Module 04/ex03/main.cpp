#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"

int main(){
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* me = new Character("me");

		AMateria* tmp;
		Floor* floor = new Floor();
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->setFloor(floor);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("iceee");
		me->equip(tmp);

		me->setFloor(0);
		me->unequip(0);
		me->unequip(1);
		me->setFloor(floor);
		me->unequip(0);
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);


		Character* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		delete bob;
		delete me;
		delete src;
		delete floor;
	}

	return 0;
}
