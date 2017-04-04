/*函数模板的使用*/
#include<iostream>
#include<string>
using namespace std;  // 在定义模板时typename和class等效
template<typename T1>  // 定义模板函数第一步  
//template<class T>  // 要在模板中使用T1不能在这中间扎入代码，因为上一句代码只是定义的第一步
T1 add(T1 a, T1 b)  // 模板函数，模板函数不需要在函数名后面加<T1>
{
	T1 c = a + b;
	return c;
}
template<class T>  // 定义一个Max的模板类
class Max {
public:
	Max(T first, T second, T third);
	T getMax();
private:
	T first_;
	T second_;
	T third_;
};
template<class T>  // 之所以这里还是要用T，是因为在类中声明时用的是T，这里如果又声明成T2，则类中函数声明找不到定义
Max<T>::Max(T first, T second, T third) :first_(first), second_(second), third_(third) {};  // Max<T>类名后面的尖括号内为用到的参数，格式就是这样
template<typename T>
T Max<T>::getMax() 
{
	T t;
	t = first_ > second_ ? first_ : second_;
	t = t > third_ ? t : third_;
	return t;
}
int main()
{
	int i;
	i = add(3, 4);  // 模板函数的使用
	cout << i << endl;
	float f;
	f = add(3.1, 4.0);
	cout << f << endl;
	string str1 = "test1";  // typename也可用来代替类
	string str2 = "test2";
	string str;
	str = add(str1, str2);
	cout << str << endl;
	Max<int> i_max(1, 2, 3);  // 定义了一个Max类，并且T都会用int代替
	cout << i_max.getMax() << endl;
	Max<char> c_max('a', 'b', 'c');
	cout << c_max.getMax() << endl;
}