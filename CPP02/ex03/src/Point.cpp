#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{

}

Point::Point(const float x, const float y) : _x(x), _y(y)
{

}

Point::Point(const Point& other)
{
	*this = other;
}

Point& Point::operator=(const Point& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	const_cast<Fixed&>(this->_x) = rhs.getX();
	const_cast<Fixed&>(this->_y) = rhs.getY();
	
	return (*this);
}

Point::~Point()
{

}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}
