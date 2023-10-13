#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

Fixed::Fixed() : _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << _fractBits);
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	// this->setRawBits(static_cast<int>(roundf((value * std::pow(2, _fractBits)))));
	this->setRawBits(static_cast<int>(roundf((value * 256))));
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractBits));
}

int Fixed::toInt( void ) const
{
	return (this->getRawBits() >> _fractBits);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return Fixed (this->getRawBits() + rhs.getRawBits());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return Fixed (this->getRawBits() - rhs.getRawBits());
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	long long tmpnum = (this->getRawBits() * rhs.getRawBits()) / (1 << _fractBits);
	Fixed tmp;
	tmp.setRawBits(tmpnum);
	return tmp;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	long long tmpnum = ((this->getRawBits() / (1 << _fractBits)) / (rhs.getRawBits()));
	Fixed tmp;
	tmp.setRawBits(tmpnum);
	return tmp;
}

Fixed& Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f2);
	else
		return (f1);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f2);
	else
		return (f1);
}