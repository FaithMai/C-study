#include "Circle.h"
class Cylinder :public Circle
{
public:
	Cylinder(float = 0, float = 0, float = 0, float = 0);
	void set_height(float height)
	{
		height_ = height;
	}
	float get_height() const
	{
		return height_;
	}
	float volume() const
	{
		return (2 * Circle::area() + 2 * 3.14159*radius_*height_);
	}
	friend ostream &operator<<(ostream &, const Cylinder &);
protected:
	float height_;
};
