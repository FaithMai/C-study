#include"Teacher.h"
Teacher::Teacher(char *name, int teach):People(name)  // 调用父类的构造函数对继承的成员进行初始化
{
	m_teach = teach;
	cout << "Teacher constructed" << endl;
}
Teacher::~Teacher()
{
	cout << "Teacher deconstructed" << endl;
}