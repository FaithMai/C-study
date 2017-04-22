/*学习继承和多态时，对类的指针类型在调用函数和成员上的一点思考。*/
/*详情请移步：http://blog.csdn.net/FaithMai/article/details/70478187*/
#include<iostream>
#include<string>
using namespace std;
class Shape {
public:
	Shape(string name)
	{
		name_ = name;
	}
	void fun()
	{
		cout << "i am Shape " <<name_<< endl;
	}
protected:
	string name_;
};
class Circle :public Shape {
public:
	Circle(string name) :Shape(name){}
	void fun()
	{
		cout << "i am Circle " <<name_<< endl;
	}
	void func()
	{
		cout << "test" << endl;
	}
protected:
	int id_new_;
};
int main() 
{
	Circle circle1("son");
	Shape shape1("father");
	Shape *shape_point1;  // 父类指针可以指向子类
	Circle *circle_point1;
//	p = new Shape;  // 不能用子类指针指向父类对象，即不能将父类对象赋值给子类指针，数据不够
	shape_point1 = &shape1;  // 父类指父类
	cout << "Shape->Shape fun()";
	shape_point1->fun();
	cout << endl;
	shape_point1 = &circle1;  // 父类指子类，调用父类的函数，子类的成员
	cout << "Shape->Circle fun()";
	shape_point1->fun();
//	shape->func();  // 调不到父类未定义的函数
	cout << endl;

	shape_point1 = &shape1;
	circle_point1 = &circle1;
//	circle = &shape1;  // 父类不能指向子类
//	(Shape*)circle = shape;  错的
	circle_point1 = (Circle*)shape_point1;  // 将子类指针指向父类对象
	cout << "Circle = Shape* ->Shape ";
	circle_point1->fun();  // 调用子类函数，父类成员，并且可以调用子类中才定义的成员
	circle_point1->func();
	cout << endl << endl;


	Circle circle2("son2");
	Shape shape2("father2");
	Shape *shape_point2;
	Circle *circle_point2;
//	circle_point2 = &((Circle)shape2);  // 不存在用户定义的Shape到Circle的类型转换
	shape_point2 = &((Shape)circle2);  // 将子类对象强制转换为父类对象
	shape_point2->fun();  // 结果令人震惊，子类的成员不见了，数据丢失
//	shape->func();  // 调不到子类成员函数
}