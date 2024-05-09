#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
private:
	int contactsCnt;
	int contactsIdx;
	Contact	contacts[8];
	bool check_avail(const std::string& str);
	void print_width_10(const std::string& str);
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();
};

#endif
