#pragma once

#include <iostream>

class Fixed {
	public:
		// construstors
		Fixed();
		Fixed(const Fixed& other);

		// returns the raw value of the fixed-point value
		int getRawBits( void ) const;
		// sets the raw value of the fixed-point number
		void setRawBits( int const raw );

		// destructor
		~Fixed();

	private:
		// store the fixed-point number value
		int fix;
		// store the number of fractional bits
		static const int fractionalBits;
};
