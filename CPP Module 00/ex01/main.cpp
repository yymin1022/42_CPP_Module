#include <iostream>
#include "PhoneBook.hpp"

int main(){
	std::string input;
	PhoneBook phoneBook;

	while(true){
		std::cout << "1. ADD\n2. SEARCH\n3. EXIT\nInput> ";
		getline(std::cin, input);

		if(input == "ADD"){
			phoneBook.add_contact();
		}else if(input == "SEARCH"){
			phoneBook.search_contact();
		}else if(input == "EXIT"){
			break;
		}else{
			std::cout << "Invalid Command!" << std::endl;
		}
	}

	return 0;
}
