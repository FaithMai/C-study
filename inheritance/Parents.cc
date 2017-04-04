#include"Parents.h"
Parents::Parents(char *name, int idea) :People(name), m_idea(idea)  //调用父类的构建函数，由于m_id是const型，所以通过这种方式初始化
{
	cout << "Parents constructed" << endl;
}
Parents::~Parents()
{
	cout << "Parents deconstructed" << endl;
}