#pragma once

#include <string>
#include <iostream>

using std::string;
using std:: cout;
using std:: endl;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const string& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		void incrementGrade();
		void decrementGrade();

		void getName() const;
		const string& getGrade();

	private:
		const string _name;
		int _grade;
};

ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
