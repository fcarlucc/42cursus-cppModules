#include "PhoneBook.hpp"
#include "Contact.hpp"

static void start(PhoneBook phoneBook) {

	std::string input;
	static int count = 0;
	std::cout << "\033[32mADD\t\t\033[38;5;208mSEARCH\t\t\033[31mEXIT\n\n\033[0m- > ";
	clearerr(stdin);
	std::cin.clear();
	std::getline(std::cin, input);
	

	if (input == "ADD") {
		phoneBook.addContact();
		if (count < 8)
			count++;
	}
	else if (input == "SEARCH")
		phoneBook.searchContact(count);
	else if (input == "EXIT") {
		std::cout << "\n\033[31m👋\033[0m\n";
		return ;
	}
	start(phoneBook);
}

int main() {

	PhoneBook	phoneBook;

	start(phoneBook);
	return 0;
}
