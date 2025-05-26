#pragma once

#include <iostream>

class Fixed {
	public:
		// Default construstor
		Fixed();
		// Copy constructor
		Fixed(const Fixed& other);
		// Copy assignment operator
		Fixed& operator=(const Fixed& other);
		// Destructor
		~Fixed();

		// returns the raw value of the fixed-point value
		int getRawBits(void) const;
		// sets the raw value of the fixed-point number
		void setRawBits(int const raw);

	private:
		// store the fixed-point number value
		int _fix;
		// store the number of fractional bits
		static const int _fractionalBits = 8;
};
