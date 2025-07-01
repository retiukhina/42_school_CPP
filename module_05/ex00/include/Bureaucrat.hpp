#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <sstream>

using std:: string;
using std:: cout;
using std:: cerr;
using std:: endl;
using std:: ostream;
using std:: exception;

class Bureaucrat {
	private:
		static const string DEFAULT_NAME;
		static const int DEFAULT_GRADE;
		const string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		void incrementGrade();
		void decrementGrade();

		const string& getName() const;
		void setGrade(const int grade);
		int getGrade() const;

		class GradeTooHighException : public exception {
			private:
				string _message;

			public:
				GradeTooHighException(int grade);
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public exception {
			private:
				string _message;

			public:
				GradeTooLowException(int grade);
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
};

ostream& operator<<(ostream& os, const Bureaucrat& bureaucrat);
