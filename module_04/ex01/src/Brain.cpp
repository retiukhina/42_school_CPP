#include "../include/Brain.hpp"

Brain::Brain(): _ideas() {
	cout << *this << " called Brain default constructor" << '\n';
}

Brain::~Brain() {
	cout << *this << " called Brain destructor" << '\n';
}

Brain::Brain(const Brain& other) {
	cout << *this << " called copy constructor" << '\n';
	for (int i = 0; i < _n; ++i) {
		_ideas[i] = other._ideas[i];
	}
}

ostream& operator<<(ostream& os, const Brain& brain) {
	brain.print(os);
	return os;
}

void Brain::swap(Brain& other) {
	std::swap(_ideas, other._ideas);
}

void Brain::print(std::ostream& os) const {
	os << "Brain at " << this;
}

void Brain::setIdea(const string& keyword, const string& message) {
	for (int i = 0; i < _n; ++i) {
		if (_ideas[i].empty()) {
			_ideas[i] = keyword + ": " + message;
		}
		return;
	}
	cerr << "Brain is full by ideas, can't get more!";
}

string Brain::getIdea(const string& keyword) const {
	for (int i = 0; i < _n; ++i) {
		size_t pos = _ideas[i].find(": ");
		if (pos != string::npos && _ideas[i].substr(0, pos) == keyword) {
			return _ideas[i].substr(pos + 2);
		}
	}
	return "No ideas for this word";
}
