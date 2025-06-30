#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <sstream>
#include "Bureaucrat.hpp"

using std:: string;
using std:: cout;
using std:: cerr;
using std:: endl;
using std:: ostream;
using std:: exception;

// Reuse the grade boundary logic from Bureaucrat, applying it to Form’s grade requirements

class AForm {
    private:

        static const int LOWEST_GRADE = 150;
	    static const int HIGHEST_GRADE = 1;
        enum { defaultGradeToSign = 1, defaultGradeToExecute = 1 };
        const string _name; // Const, the name doesn't change once a form is created
        const int _gradeToSign; // Const, the grade doesn't change once a form is created
        const int _gradeToExecute;
        bool _ifSigned; // Non-const, the value can be changed

    public:
        AForm(const string& name);
        AForm(const string& name, int sGrade, int eGrade);
        AForm(const AForm& other);
        AForm();
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const string& getName() const;
        bool ifSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        int checkGradeToSign(const int grade);

        void beSigned(const Bureaucrat& b);
        virtual void execute(const Bureaucrat& executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
