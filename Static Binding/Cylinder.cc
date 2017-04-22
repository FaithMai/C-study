#include "Cylinder.h"
Cylinder::Cylinder(float x,float y, float r, float height):Circle(x,y,r)  // 调用Circle类的构造函数进行数据初始化
{
	height_ = height;
}
ostream & operator<<(ostream &output, const Cylinder &cy)
{
	output << "Center = [" << cy.x_ << "," << cy.y_ << "], r = " << cy.radius_ << ", h = " << cy.height_ << "\nare = " << cy.area() << ", volume = " << cy.volume() << endl;
	return output;
}
