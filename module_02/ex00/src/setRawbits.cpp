#include "../include/Fixed.hpp"

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fix = raw;
}
