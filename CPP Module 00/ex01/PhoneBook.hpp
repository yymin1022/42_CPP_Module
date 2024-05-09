#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	int contactsIdx;
	Contact	contacts[8];
	bool check_avail(std::string& str);
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();
};

#endif
