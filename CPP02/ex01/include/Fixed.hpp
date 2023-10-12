#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
	
	private:
		int _value;
		static const int _fractBits = 8;
};

#endif