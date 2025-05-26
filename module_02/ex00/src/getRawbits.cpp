#include "../include/Fixed.hpp"

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fix;
}
