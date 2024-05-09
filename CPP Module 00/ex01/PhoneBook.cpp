#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contactsCnt(0), contactsIdx(0){}
PhoneBook::~PhoneBook(){}

bool PhoneBook::check_avail(const std::string& str){
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


void PhoneBook::print_width_10(const std::string& str){
	std::string tmp;
	if(str.length() <= 10){
		tmp = str;
	}else{
		tmp = str.substr(0, 9);
		tmp.append(".");
	}
	std::cout << "|";
	std::cout.width(10);
	std::cout << tmp;
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

	std::cout << "Enter Nickname: ";
	while(!getline(std::cin, input) || !check_avail(input)){
		std::cout << "Enter Nickname: ";
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
	if(this->contactsCnt < 8){
		this->contactsCnt++;
	}
	std::cout << "Contact Added!" << std::endl;
}

void PhoneBook::search_contact(){
	if(this->contactsCnt == 0){
		std::cout << "No Contacts Added!" << std::endl;
		return;
	}

	print_width_10("Index");
	print_width_10("First Name");
	print_width_10("Last Name");
	print_width_10("Nickname");
	std::cout << "|" << std::endl;

	for(int i = 0; i < this->contactsCnt; i++){
		std::stringstream ss;
		ss << i;
		print_width_10(ss.str());

		Contact cur = this->contacts[i];
		print_width_10(cur.getFirstName());
		print_width_10(cur.getLastName());
		print_width_10(cur.getNickName());
		std::cout << "|" << std::endl;
	}

	std::cout << "Enter Index: ";
	std::string input;
	if(!getline(std::cin, input) || input.empty() || input.length() != 1 || !isdigit(input[0])){
		std::cout << "Invalid Input!" << std::endl;
		return;
	}

	int idx = strtol(input.c_str(), 0, 10);
	if(idx < 0 || idx >= this->contactsCnt){
		std::cout << "Invalid Input!" << std::endl;
		return;
	}
	std::cout << "First Name: " << this->contacts[idx].getFirstName() << "\n";
	std::cout << "Last Name: " << this->contacts[idx].getLastName() << "\n";
	std::cout << "Nickname: " << this->contacts[idx].getNickName() << "\n";
	std::cout << "Phone Number: " << this->contacts[idx].getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << this->contacts[idx].getDarkestSecret() << "\n";
}
