#include "Point.hpp"
Point::Point() : x(Fixed(0)),y(Fixed(0)){}
Point::Point(const Fixed &x, const Fixed &y) : x(x),y(y){}
Point::~Point(){}
Point::Point(const Point &a): x(a.get_x()), y(a.get_y()){}
Point& Point::operator= (const Point &a) {
	if(this != &a)
		*this = a;
	return *this;
}
float Point::get_x() const {return x.toFlot();}
float Point::get_y() const {return y.toFlot();}