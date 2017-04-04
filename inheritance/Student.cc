#include"Student.h"
Student::Student(char *name, int tech, int idea, Homework my_homework, int test):People(name),Parents(name, idea),Teacher(name,tech),m_my_homework(my_homework)
{
	m_test = test;
	cout << "Student constructed" << endl;
}
Student::~Student()
{
	cout << "Student deconstructed" << endl;
}