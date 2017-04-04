/*常对象的学习*/
#include<iostream>
#include<string>
using namespace std;
class Student {
public:
	Student(int i, string);
	void setId(int i){
		this->id = i;
	}
	// 下方两个函数构成两个重载的函数，const的实例调用const的函数。因为常成员函数不能改变成员的值
	// 一般实例能够调用const函数和一般函数，但是调用const函数就失去了修改成员值的能力
	int getId() const {
		return this->id;
	}
	int getId(){
		return this->id;
	}
	string getName() const {
		return name;
	}
	//string getName() {
	//	return name;
	//}
private:
	int id;
	const string name;  // 常成员
};
Student::Student(int i, string pStr):name(pStr)  //后面的冒号是构造函数的对成员变量的赋值方法，更常用于const型变量，因为const型变量没办法通过后面的代码赋值
{
	id = i;
}
int main()
{
	Student const stu(7,"name1");  // const实例需要在初始化的时候确定值，之后不能够再被改变
	int i = stu.getId();
	cout << i << " " << stu.getName() << endl;
	Student stu2(7,"name2");  // 一般实例可以进行值的修改
	stu2.setId(8);
	cout << stu2.getId() <<" "<< stu2.getName() << endl;
}