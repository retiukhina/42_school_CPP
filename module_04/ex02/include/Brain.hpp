#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using std::string;
using std:: cout;
using std:: endl;
using std::cerr;
using std::ostream;

class Brain {
	private:
		static const int _n = 100;
		string _ideas[_n];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(Brain other);
		~Brain();
		void swap(Brain& other);

		void print(std::ostream& os) const;

		void setIdea(const std::string& keyword, const std::string& message);
		string getIdea(const string& keyword) const;
};

ostream& operator<<(std::ostream& os, const Brain& brain);


