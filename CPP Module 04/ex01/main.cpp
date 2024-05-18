#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();
	std::cout << j2->getType() << " " << std::endl;
	j2->makeSound();
	meta2->makeSound();

	delete meta;
	delete j;
	delete i;
	delete meta2;
	delete j2;

	return 0;
}
