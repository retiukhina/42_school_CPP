#include "../include/Fixed.hpp"

Fixed::Fixed() : _fix(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fix = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Copy constructor called" << std::endl;
}


