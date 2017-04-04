/*说明：
构造函数，析构函数，继承，二义性，虚基类
People中含有m_name成员变量
Parents继承自People类，继承方式为virtual public，避免了二义性的情况，含m_idea成员变量
Teacher继承自People类，继承方式为virtual public，含m_tea成员变量
Homework为另外的类，含m_work成员变量
Student继承自Parents和Teacher类，含m_my_homework，m_test成员，如果不是虚继承，Student就会具有两个m_name成员，造成二义性

Student类构造函数写法：
将所需要的参数全部写在形参列表中，在分别从上往下调用父类的构造函数，需要注意的是name使用People中的构造函数，而Parents和Teacher中的构造函数有name，此时系统会忽略name，只管其他变量，然后是对象成员的赋值，常量的赋值，最后将一般量写在大括号中进行赋值
构造函数调用顺序:
首先是Homework，即Student包含的成员，之后是最上层父类，之后依次往下，最后是自己
析构函数调用顺序:
先释放对象成员变量，之后自身，再逐级向上释放到最上层父类
*/
#include"Student.h"
int main()
{
	Student student1("people", 1, 2, 'h', 3);
	return 0;
}