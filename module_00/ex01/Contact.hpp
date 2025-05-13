// Store and manage the information about the contact
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
	private:
		std::string	index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		void		setFirstName(const std::string& firstName);
		void		setLastName(const std::string& lastName);
		void		setNickName(const std::string& nickName);
		void		setPnoneNumber(const std::string& lastName);
		void		setDarkestSecret(const std::string& nickName);
		//std::string	getFirstName() const;
		//std::string	getLastName() const;
		//std::string	getNickName() const;
};

#endif
