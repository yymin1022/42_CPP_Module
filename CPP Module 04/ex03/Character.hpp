#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"

class Character: public ICharacter{
	private:
		std::string _name;
		AMateria* _inventory[4];
		Floor* _floor;

	public:
		Character();
		Character(const Character& obj);
		~Character();
		Character& operator=(const Character& obj);
		Character(std::string const & name);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		void setFloor(Floor* floor);
};

#endif

