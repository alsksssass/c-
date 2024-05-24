#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float p1 = cross_pd(a,b,point);
	float p2 = cross_pd(b,c,point);
	float p3 = cross_pd(c,a,point);

	bool all_pos = (p1 > 0) && (p2 > 0) && (p3 > 0);
	bool all_neg = (p1 < 0) && (p2 < 0) && (p3 < 0);
	if(all_pos || all_neg)
		return true;
	return false;
}

float cross_pd(Point const a, Point const b, Point const c)
{return (b.get_x() - a.get_x()) * (c.get_y() - a.get_y()) - (b.get_y() - a.get_y()) * (c.get_x() - a.get_x());}