/*用与对相同长度的字符串进行排序*/
#include<iostream>
using namespace std;
bool constractFunc(char *a, char *b)  // 对字符串进行比较的函数
{
	while (*a != NULL)
	{
		if (*a > *b)
			return true;
		else if (*a < *b)
			return false;
		else
		{
			a++;
			b++;
		}
	}
	return true;
}
void exchange(char *a, char *b)  // 交换字符串的函数
{
	char temp;
	while (*a != NULL)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		a++;
		b++;
	}
}
void sortFunc(char (*a)[5])  // 排序的函数，注意因为是二维数组，相当于指针常量，即地址一定，不能改变，只能改变指向的内容
{
	char *temp;
	for(int i = 0; i < 9; i++)
		for (int j = i+1; j < 10; j++)
		{
			if (constractFunc(a[i], a[j]))
				exchange(a[i], a[j]);
		}
	cout << "排序为:" << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
}

int main()
{
	char str[10][5];
	for (int i = 0; i < 10; i++)
		cin >> str[i];
	sortFunc(str);
	return 0;
}