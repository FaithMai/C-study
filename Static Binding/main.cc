/*多态中的静态联编*/
#include<iostream>
#include"Point.h"
#include"Circle.h"
#include"Cylinder.h"
using namespace std;
int main()
{
	Point p(3.5, 6.4);  // 实例化Point
	cout << "x = " << p.get_x() << ",y = " << p.get_y() << endl;  // 调用Point的函数，访问成员变量
	p.set_point(8.5, 6.8);  // 对成员函数重新赋值的函数
	cout << "p(new)" << p << endl;
	Circle c(3.5, 6.4, 5.2);  // 实例化Circle类
	cout << "origin circle:\n x = " << c.get_x() << ", y = " << c.get_y() << ", r = " << c.get_radius() << ", area = " << c.area() << endl;  // 通过静态联编使Circle类的实例调用继承的同名get_x(),get_y()函数，实现了多态
	c.set_radius(7.5);  // 调用类中定义的函数
	c.set_point(5, 5);  // 静态联编实现了多态
	cout << "new circle:\n" << c;
	Point &p_ref = c;   // 用基类指针指向派生类的对象
	cout << "p_ref:" << p_ref << endl;  // 调用的是基类Point重载的输出函数
	Cylinder cy1(3.5, 6.4, 5.2, 10);
	cout << "origin cylinder:\nx = " << cy1.get_x() << ",y = " << cy1.get_y() << ",r = " << cy1.get_radius() << ",h = " << cy1.get_height() << "\narea = " << cy1.area() << ",volume = " << cy1.volume() << endl;
	cy1.set_height(15);
	cy1.set_radius(7.5);
	cy1.set_point(5,5);
	cout << "\nnew cylinder:\n" << cy1;
	Point &p_ref2 = cy1;  // 用基类Point的指针指向子类，调用基类Point重载的输出函数
	cout << "\np_ref as a Point:" << p_ref2;
	Circle &c_ref = cy1;  // 用基类Circle的指针指向子类，调用的是基类Circle重载输出函数
	cout << "\nc_ref as a Circle:" << c_ref;
	return 0;
}