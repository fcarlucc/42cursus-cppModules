#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {

	private:

		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:

		void createContact();

		Contact();
		Contact(const std::string first, const std::string last, const std::string nick, const std::string phone, const std::string secret);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		void setFirstName(const std::string first);
		void setLastName(const std::string last);
		void setNickName(const std::string nick);
		void setPhoneNumber(const std::string phone);
		void setDarkestSecret(const std::string secret);

		std::string toString() const;
};

#endif
