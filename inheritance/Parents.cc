#include"Parents.h"
Parents::Parents(char *name, int idea) :People(name), m_idea(idea)  //���ø���Ĺ�������������m_id��const�ͣ�����ͨ�����ַ�ʽ��ʼ��
{
	cout << "Parents constructed" << endl;
}
Parents::~Parents()
{
	cout << "Parents deconstructed" << endl;
}