#ifndef _TEACHER_H_
#define _TEACHER_H_
#include"People.h"
class Teacher:virtual public People {  // ��People����Teacher�������̳�
public:
	Teacher(char *, int);
	~Teacher();
private:
	int m_teach;
};
#endif
