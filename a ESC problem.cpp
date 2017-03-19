//存疑：本来用于将最后一个逗号去掉，发现这样不能去掉'\b'。另外，在c++中中文逗号竟然不能以中文字符形式输出，只能用字符串形式
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
			cout << '\b' << endl;  //本来用于将最后一个逗号去掉，发现这样不能去掉。
		}
	}
	return 0;
}
int judge_func(int m)   //用于判断是否为完数的函数
{
	int total = 0;
	for (int i = 1; i <= (m+1) / 2; i++)
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
	cout << m << ',' << "its factors are ";
	for (int i = 1; i <= (m+1) / 2; i++)
	{
		if (m%i == 0)
			cout << i << "，";
		//cout<<'\b';   如果将'\b'这个字符放到这里就可以使得输出的字符回退一位
	}
}