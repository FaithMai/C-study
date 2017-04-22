#include "Point.h"
Point::Point(float x, float y)
{
	this->x_ = x;
	this->y_ = y;
}
void Point::set_point(float x, float y)
{
	this->x_ = x;
	this->y_ = y;
}
ostream & operator<<(ostream & output, const Point & p)
{
	output << "[" << p.x_ << "," << p.y_ << "]" << endl;
	return output;
}
