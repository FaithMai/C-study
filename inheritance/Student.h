#ifndef _STUDENT_H_
#define _STUDENT_H_
#include"Teacher.h"
#include"Parents.h"
#include"Homework.h"
class Student :public Parents,public Teacher{  // 继承的先后会使得先construct哪个对象，左边的先
public:
	Student(char *, int, int, Homework, int);
	~Student();
private:
	Homework m_my_homework;
	int m_test;
};
#endif