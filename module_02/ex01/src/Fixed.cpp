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
    std::cout << "Destructor called" << std::endl;
}

// Multiplies the integer by 256 (shifting left by 8) to store it as fixed-point
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->_fix = n << _FRACTIONALBITS;
}

// Multiplies the float by 256 and rounds to nearest int to convert to fixed-point
Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->_fix = roundf(f * (1 << _FRACTIONALBITS));
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}



