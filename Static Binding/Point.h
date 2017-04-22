#ifndef _POINT_H_  // 放置定义的类重复定义，造成程序崩溃
#define _POINT_H_
#include<iostream>
using namespace std;
class Point
{
public:
	Point(float = 0, float = 0);
	void set_point(float, float);
	float get_x() const
	{
		return x_;
	}
	float get_y() const
	{
		return y_;
	}
	friend ostream &operator <<(ostream &output, const Point &p);  // 
protected:
	float x_, y_;

};
#endif
