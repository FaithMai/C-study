#ifndef _PEOPLE_H_
#define _PEOPLE_H_
//  ����ͷ�ļ��У����Ƕ��塣���ԣ�Ϊ�˱����ظ����壬Ҫ��#ifndef��#define�����ơ�
#include<iostream>
using namespace std;
class People {
public:
	People(char *);
	~People();
private:
	char *m_name;
};	
#endif