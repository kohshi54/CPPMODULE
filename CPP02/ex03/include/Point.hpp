#include "Fixed.hpp"

#ifndef __POINT_HPP__
#define __POINT_HPP__

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point& operator=(const Point& rhs);
		~Point();

		Fixed getX() const;
		Fixed getY() const;

	private:
		const Fixed _x;
		const Fixed _y;
};

#endif