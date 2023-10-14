#include "Fixed.hpp"
#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	const Point a(0, 0);
	const Point b(8, 0);
	const Point c(0, 8);

	const Point point(1, 1);
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}