#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	public:
		// Default construstor
		Fixed();
		// Copy constructor
		Fixed(const Fixed& other);
		// Copy assignment operator
		Fixed& operator=(const Fixed& other);
		// Constructor to convert convert int to the fixed-point value
		Fixed(const int);
		// Constructor to convert float to the corresponding fixed-point value
		Fixed(const float);
		// Destructor
		~Fixed();

		// Returns the raw value of the fixed-point value
		int getRawBits(void) const;
		// Sets the raw value of the fixed-point number
		void setRawBits(int const raw);
		// Converts the fixed-point value to a floating-point value
		float toFloat( void ) const;
		// Converts the fixed-point value to an integer value
		int toInt( void ) const;

		// Overloaded comparison operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

		// Overloaded arithmetic operators
		Fixed& operator+=(const Fixed& other);
		const Fixed operator+(const Fixed& other) const;
		Fixed& operator-=(const Fixed& other);
		const Fixed operator-(const Fixed& other) const;
		Fixed& operator*=(const Fixed& other);
		const Fixed operator*(const Fixed& other) const;
		Fixed& operator/=(const Fixed& other);
		const Fixed operator/(const Fixed& other) const;

		// Overloaded increment/precrement operators
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

        // Overloaded functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max (Fixed& a, Fixed& b);
        static const Fixed& max (const Fixed& a, const Fixed& b);

	private:
		// store the fixed-point number value
		int _fix;
		// store the number of fractional bits
		static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);
