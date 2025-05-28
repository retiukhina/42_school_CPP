#include "../include/Fixed.hpp"

bool Fixed::operator>(const Fixed& other) const {
	return this->_fix > other._fix;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_fix < other._fix;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_fix >= other._fix;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_fix >= other._fix;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_fix == other._fix;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_fix != other._fix;
}

Fixed& Fixed::operator+=(const Fixed& other) {
	this->_fix += other._fix;
	return *this;
}

Fixed& Fixed::operator-=(const Fixed& other) {
	this->_fix -= other._fix;
	return *this;
}

Fixed& Fixed::operator*=(const Fixed& other) {
	this->_fix = (this->_fix * other._fix) >> _fractionalBits;
	return *this;
}

Fixed& Fixed::operator/=(const Fixed& other) {
	this->_fix = (this->_fix << _fractionalBits) / other._fix;
	return *this;
}

const Fixed Fixed::operator+(const Fixed& other) const {
	Fixed sum = *this;
	sum += other;
	return sum;
}

const Fixed Fixed::operator-(const Fixed& other) const {
	Fixed dif = *this;
	dif -= other;
	return dif;
}

const Fixed Fixed::operator*(const Fixed& other) const {
	Fixed mult = *this;
	mult *= other;
	return mult;
}

const Fixed Fixed::operator/(const Fixed& other) const {
	Fixed mult = *this;
	mult /= other;
	return mult;
}

Fixed& Fixed::operator++() {
	this->_fix += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_fix += 1;
	return tmp;
}

Fixed& Fixed::operator--() {
	this->_fix -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_fix -= 1;
	return *this;
}
