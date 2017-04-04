#include"Homework.h"
Homework::Homework(char work)
{
	m_work = work;
	cout << "Homework constructed" << endl;
}
Homework::~Homework()
{
	cout << "Homework deconstructed" << endl;
}