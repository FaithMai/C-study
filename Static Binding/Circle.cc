#include "Circle.h"
Circle::Circle(float x, float y, float radius):Point(x,y)
{
	radius_ = radius;
}

void Circle::set_radius(float radius)
{
	radius_ = radius;
}

float Circle::get_radius() const
{
	return radius_;
}

float Circle::area() const
{
	return 3.14159 * radius_ * radius_;
}
ostream &operator<<(ostream &output, const Circle &c)  // 重载了输出函数
{
	output << "Center = [" << c.x_ << "," << c.y_ << "],r = " << c.radius_ << ",area = " << c.area() << endl;
	return output;
}
