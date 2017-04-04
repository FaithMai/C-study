/*友元函数的学习*/
#include<iostream>
#include<string>
using namespace std;
class Doctor {
public:
	void cureStudent();
};
class Teacher {
public:
	void createStudent();
};
class Student {
public:
	void setName(string pName);
	friend void Teacher::createStudent();  // 声明Teacher类中的createStudent函数是Student的友元函数
	friend void print(Student &pstu);   // 声明一般函数print为Student的友元函数
	void sPrint(Student stu);
	friend class Doctor;  // 将类Doctor声明为Student的友元类，Doctor中的所有函数都能够访问Student的成员数据
private:
	int id;
	string name;
};
void Student::setName(string pName)
{
	this->name = pName;
}
void Teacher::createStudent()  //友元函数可以对Student类的所有成员数据进行访问，但首先需要对Student进行实例化
{
	Student a;
	a.name = "类友元函数";  // 需要注意的是，要将Teacher定义在Student类之前才会有效
	a.id = 3;
	a.sPrint(a);
}
void Doctor::cureStudent()
{
	Student a;
	a.name = "cure";
	cout << a.name << endl;
}
void Student::sPrint(Student stu)
{
	cout << stu.id << " " << stu.name << " " << endl;
}
void print(Student &pstu)   // 友元函数对Student中所有成员数据都能进行访问 
{
	//Student a;
	//a.id;    这样调用也可以做到
	cout << pstu.name << endl;
}
int main()
{
	Teacher tea1;
	tea1.createStudent();  // 通过类中友元函数访问
	Student stu1;
	stu1.setName("setName");
	print(stu1);    // 通过一般友元函数访问
	Doctor doc1;
	doc1.cureStudent();  // 通过友元类中的函数访问
}