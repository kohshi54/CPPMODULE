#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);

		float toFloat( void ) const;
		int toInt( void ) const;

		int getRawBits( void ) const;
		void setRawBits( int const raw );
	
	private:
		int _rawBits;
		static const int _fractBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif