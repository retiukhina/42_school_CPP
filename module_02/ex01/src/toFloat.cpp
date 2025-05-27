#include "../include/Fixed.hpp"

float Fixed::toFloat(void) const {
    return (float)_fix / (1 << _fractionalBits);
}
