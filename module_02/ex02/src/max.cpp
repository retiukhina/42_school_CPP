#include "../include/Fixed.hpp"

const Fixed& Fixed::max (const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}


Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
