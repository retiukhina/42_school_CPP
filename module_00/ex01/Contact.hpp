// Store and manage the information about the contact
#pragma once

#include <iostream>
#include <string>

class Contact{
	public:
		void		setFirstName(const std::string& firstName);
		void		setLastName(const std::string& lastName);
		void		setNickName(const std::string& nickName);
		void		setPhoneNumber(const std::string& lastName);
		void		setDarkestSecret(const std::string& nickName);
		//std::string	getFirstName() const;
		//std::string	getLastName() const;
		//std::string	getNickName() const;
	
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};
