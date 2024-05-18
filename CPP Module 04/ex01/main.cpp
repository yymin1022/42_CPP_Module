#include "Cat.hpp"
#include "Dog.hpp"

void leak_check(){
	system("leaks Animal");
}

int main(){
	atexit(leak_check);

	// Default Test
	const Animal* animal1 = new Cat();
	const Animal* animal2 = new Dog();
	delete animal1;
	delete animal2;

	std::cout << std::endl;

	// Copy Test
	const Cat *cat1 = new Cat();
	const Cat *cat2 = new Cat(*cat1);
	delete cat1;
	delete cat2;

	std::cout << std::endl;

	// Assignment Test
	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog();
	*dog2 = *dog1;
	delete dog1;
	delete dog2;

	return 0;
}
