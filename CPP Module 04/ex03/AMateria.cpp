#include "AMateria.hpp"

AMateria::AMateria(){}

AMateria::AMateria(const AMateria& obj): _type(obj._type){}

AMateria::~AMateria(){}

AMateria& AMateria::operator=(const AMateria& obj){
	if(this != &obj)
		_type = obj._type;
	return *this;
}

AMateria::AMateria(std::string const & type): _type(type){}

std::string const & AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter& target){
	std::cout << " * uses some materia on " << target.getName() << " *\n";
}
