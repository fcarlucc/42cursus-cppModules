#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook {

private:

	Contact contacts[8];

public:

	void addContact();
	void searchContact(int count);
	void printList(int count);
	std::string resizeValue(std::string s);

	Contact* getContacts();
};

#endif
