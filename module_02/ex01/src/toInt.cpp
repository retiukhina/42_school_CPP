#include "../include/Fixed.hpp"

int Fixed::toInt(void) const {
    return _fix >> _fractionalBits;
}
