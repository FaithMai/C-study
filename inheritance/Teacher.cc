#include"Teacher.h"
Teacher::Teacher(char *name, int teach):People(name)  // ���ø���Ĺ��캯���Լ̳еĳ�Ա���г�ʼ��
{
	m_teach = teach;
	cout << "Teacher constructed" << endl;
}
Teacher::~Teacher()
{
	cout << "Teacher deconstructed" << endl;
}