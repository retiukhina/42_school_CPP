#include "../include/Fixed.hpp"

Fixed::Fixed() : fix(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Copy constructor called" << std::endl;
}


