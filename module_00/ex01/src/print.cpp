#include "../include/Print.hpp"

bool Contact::isFilled() const {
    return !(firstName.empty() || lastName.empty() || nickName.empty()
				|| phoneNumber.empty() || darkestSecret.empty());
}

std::string Contact::formatField(const std::string& field) const {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return std::string(10 - field.length(), ' ') + field; // right-align
}

std::string Contact::printSingleContact(const int index) const {
	std::ostringstream oss;
	oss << std::setw(10) << index << "|"
		<< formatField(firstName) << "|"
		<< formatField(lastName) << "|"
		<< formatField(nickName) << std::endl;
	return oss.str();
}

void Contact::printSummary(int i) const {
	std::cout << std::setw(10) << i << "|"
			  << formatField(firstName) << "|"
			  << formatField(lastName) << "|"
			  << formatField(nickName) << std::endl;

}

void printContactsPreview(Contact contacts[], int max) {
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < max; ++i) {
			if (contacts[i].isFilled()) {
			    contacts[i].printSummary(i + 1);
			}
	}
}
