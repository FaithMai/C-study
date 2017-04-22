#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "Point.h"
class Circle : public Point
{
public:
	Circle(float = 0, float = 0, float = 0);
	void set_radius(float);
	float get_radius() const;
	float area() const;
	friend ostream &operator<<(ostream &, const Circle &);  // 声明输出流函数为友元函数
protected:
	float radius_;
};
#endif
