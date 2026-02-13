#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact() : _name(), _surname(), _nickname(), _phone(), _secret() {}

void	Contact::setFirstName(const std::string &name)
{
	_name = name;
}

void	Contact::setLastName(const std::string &surname)
{
	_surname = surname;
}

void	Contact::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

void	Contact::setPhone(const std::string &phone)
{
	_phone = phone;
}

void	Contact::setSecret(const std::string &secret)
{
	_secret = secret;
}

std::string Contact::getName() { return _name; }
std::string Contact::getLastName() { return _surname; }
std::string Contact::getNickname() { return _nickname; }
std::string Contact::getPhone() { return _phone; }
std::string Contact::getSecret() { return _secret; }
