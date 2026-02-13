#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
	public:
		Contact();

		void		setFirstName(const std::string &name);
		void		setLastName(const std::string &surname);
		void		setNickname(const std::string &nickname);
		void		setPhone(const std::string &phone);
		void		setSecret(const std::string &secret);

		std::string getName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhone();
		std::string getSecret();

	private:
		std::string _name;
		std::string _surname;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
};

#endif