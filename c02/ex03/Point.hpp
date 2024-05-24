#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Fixed;
class Point {
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const Fixed &x, const Fixed &y);
	~Point();
	Point(const Point &a);
	Point& operator = (const Point &a);
	float get_x() const;
	float get_y() const;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
float cross_pd(Point const a, Point const b, Point const c);
#endif // POINT_HPP