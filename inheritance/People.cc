#include"People.h"
People::People(char *name)
{
	this->m_name = new char[strlen(name) + 1];
	if (m_name)
		strcpy(m_name, name);
	cout << "people constructed" << endl;
}
People::~People()
{
	if (m_name)
		delete [] m_name;
	cout << "people deconstructed" << endl;
}