#include "Cat.hpp"
#include "Dog.hpp"

int main(){
	// const AAnimal* a = new AAnimal();
	// delete a;

	const AAnimal* cat = new Cat();
	const AAnimal* dog = new Dog();
	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;

	return 0;
}
