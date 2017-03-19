/*1000以内完数的输出，自己的方法实现，只是处理租后的逗号有点笨拙*/
#include<iostream>
using namespace std;
int judge_func(int);
void output_func(int);
int main()
{
	for (int i = 1; i <= 1000; i++)
	{
		if (judge_func(i))
		{
			output_func(i);
			cout << endl;
		}
	}
	return 0;
}
int judge_func(int m)   //用于判断是否为完数的函数
{
	int total = 0;
	for (int i = 1; i <= m / 2; i++)
	{
		if (m%i == 0)
			total += i;
	}
	if (total == m)
		return 1;
	else 
		return 0;
}
void output_func(int m)  //用于将完数因子进行输出的函数
{
	int i = 1;
	cout << m << "，" << "its factors are ";
	while (i <= m / 2)  // 此处用while循环为了让最后一个数字输出后，不输出逗号
	{
		if (m%i == 0)
			cout << i;
		i++;
		if (i <= m / 2 && m%i == 0)  // 对数字进行判断，如果是最后一个数字，就不输出逗号
			cout << "，";
	}
}