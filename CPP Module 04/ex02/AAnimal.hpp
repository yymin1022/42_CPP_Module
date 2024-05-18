#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class AAnimal{
protected:
	std::string type;

public:
	AAnimal();
	AAnimal(const AAnimal& obj);
	virtual ~AAnimal();
	AAnimal& operator=(const AAnimal& obj);

	std::string getType() const;
	virtual void makeSound() const = 0;
};

#endif
