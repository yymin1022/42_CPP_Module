#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contactsIdx(0){}
PhoneBook::~PhoneBook(){}

bool PhoneBook::check_avail(std::string& str){
	bool is_space_only = true;

	for(size_t i = 0; i < str.length(); i++){
		if(!isspace(str[i])){
			is_space_only = false;
		}
		if(!isprint(str[i])){
			std::cout << "Error Input" << std::endl;
			return false;
		}
	}
	if(str.length() == 0 || is_space_only){
		std::cout << "Error Input" << std::endl;
		return false;
	}
	return true;
}

void PhoneBook::add_contact(){
	Contact newContact;
	std::string input;

	std::cout << "Enter First Name: ";
	while(!getline(std::cin, input) || !check_avail(input)){
		std::cout << "Enter First Name: ";
		continue;
	}
	newContact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	while(!getline(std::cin, input) || !check_avail(input)){
		std::cout << "Enter Last Name: ";
		continue;
	}
	newContact.setLastName(input);

	std::cout << "Enter Nick Name: ";
	while(!getline(std::cin, input) || !check_avail(input)){
		std::cout << "Enter Nick Name: ";
		continue;
	}
	newContact.setNickname(input);

	std::cout << "Enter Phone Number: ";
	while(!getline(std::cin, input) || !check_avail(input)){
		std::cout << "Enter Phone Number: ";
		continue;
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter Darkest Secret: ";
	while(!getline(std::cin, input) || !check_avail(input)){
		std::cout << "Enter Darkest Secret: ";
		continue;
	}
	newContact.setDarkestSecret(input);

	this->contacts[this->contactsIdx] = newContact;
	this->contactsIdx = (this->contactsIdx + 1) % 8;
	std::cout << "Contact Added!" << std::endl;
}

void PhoneBook::search_contact(){
	std::cout << "Contact Index : " << this->contactsIdx << std::endl;
	std::cout << ">> " << this->contacts[this->contactsIdx].getPhoneNumber() << std::endl;
}
