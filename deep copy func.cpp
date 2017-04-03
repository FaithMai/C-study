/*c++中构造函数与析构函数，浅拷贝与深拷贝学习与思考*/
#include<iostream>
#include<string>
using namespace std;
class Student {
public:
	Student(int pId, string pName, char *pSex);
	Student(const Student &cStudent);  // 声明拷贝函数，只是声明，不修改默认值为浅拷贝
	~Student();
	void print();
private:
	string name;
	int id;
	char *sex;  // 当成员变量有指针时，拷贝后由于delete堆中同一空间两次，要用深拷贝，即重新定义拷贝函数
};
Student::Student(int pId, string pName, char *pSex)  
{
	this->id = pId;
	this->name = pName;
	this->sex = new char[strlen(pSex) + 1];
	if ((this->sex))
		strcpy(this->sex, pSex);  // 注意这里只能用strcpy函数，如果用指针复制，则将指针放弃了刚申请的，指向形参的堆空间
}
Student::Student(const Student &cStudent)
{
	this->id = cStudent.id;
	this->name = cStudent.name;
	this->sex = new char[strlen(cStudent.sex)+1];  // 重新在堆中申请一段内存，长度为复制的对象的成员变量指向的字符串长度
	strcpy(this->sex, cStudent.sex);  // 再将复制的对象相应内容复制到目标对象中，这样使得指针成员变量指向变，堆区中内存变，但内容相同
}
Student::~Student()  // 析构函数只能用于释放对象的成员变量
{
	delete []sex;  // 成员变量中如果有在堆中申请的变量，则要通过析构函数的delete释放
}
void Student::print()
{
	cout << this->id << " " << this->name << " " << this->sex << endl;
}
int main()
{
	Student a(10, "test","man");
	a.print();
	Student b(50, "2test","man");
	b.print();
	Student *c = new Student(100, "3test", "woman");
	c->print();
	delete c;  // 释放的是实例本身
	c = NULL;
	Student d(a); // 调用拷贝函数
	d.print();
	return 0;
}