#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

std::string Contact::getDarkestSecret() const{
	return this->darkestSecret;
}

std::string Contact::getFirstName() const{
	return this->firstName;
}

std::string Contact::getLastName() const{
	return this->lastName;
}

std::string Contact::getNickName() const{
	return this->nickName;
}

std::string Contact::getPhoneNumber() const{
	return this->phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret){
	this->darkestSecret = darkestSecret;
}

void Contact::setFirstName(std::string firstName){
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName){
	this->lastName = lastName;
}

void Contact::setNickname(std::string nickName){
	this->nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber){
	this->phoneNumber = phoneNumber;
}
