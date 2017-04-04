#ifndef _TEACHER_H_
#define _TEACHER_H_
#include"People.h"
class Teacher:virtual public People {  // 将People当做Teacher的虚基类继承
public:
	Teacher(char *, int);
	~Teacher();
private:
	int m_teach;
};
#endif
