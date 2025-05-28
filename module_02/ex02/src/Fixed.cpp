#include "../include/Fixed.hpp"

#define DEBUG

Fixed::Fixed() : _fix(0) {
	#ifdef DEFINE
    std::cout << "Default constructor called" << std::endl;
	#endif
}

Fixed::Fixed(const Fixed& other) {
	#ifdef DEFINE
    std::cout << "Copy constructor called" << std::endl;
	#endif
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	#ifdef DEFINE
    std::cout << "Copy assignment operator called" << std::endl;
	#endif
    if (this != &other) {
        this->_fix = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
	#ifdef DEFINE
    std::cout << "Destructor called" << std::endl;
	#endif
}

// Multiplies the integer by 256 (shifting left by 8) to store it as fixed-point
Fixed::Fixed(const int n) {
	#ifdef DEFINE
    std::cout << "Int constructor called" << std::endl;
	#endif
    this->_fix = n << _fractionalBits;
}

// Multiplies the float by 256 and rounds to nearest int to convert to fixed-point
Fixed::Fixed(const float f) {
	#ifdef DEFINE
    std::cout << "Float constructor called" << std::endl;
	#endif
    this->_fix = roundf(f * (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}



