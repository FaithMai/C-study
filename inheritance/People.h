#ifndef _PEOPLE_H_
#define _PEOPLE_H_
//  由于头文件中，类是定义。所以，为了避免重复定义，要用#ifndef和#define来控制。
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