/*验证哥德巴赫的猜想*/
#include<iostream>
using namespace std;
bool prime(int);
int gotbaha(int);
int main()
{
	int num;
	cout << "please input a number:" << endl;
	cin >> num;
	gotbaha(num);
	return 0;
}
int gotbaha(int y)  // 两质数输出的函数
{
	if (y <= 2)  // 对2以下数字的判断
		cout << "data error" << endl;
	int i, j;
	for (i = 2; i <= y / 2; i++)  //第一个数
		if (prime(i))
		{
			for (j = i; j < y; j++)  // 第二个数
			{
				if (prime(j))
				{
					if (y == i + j)
					{
						cout << y << "=" << i << "+" << j << endl;
						return 0;
					}
				}
			}
		}
}
bool prime(int x)  // 用于判断是否为质数的函数
{
	if (x <= 1)
		return false;
	for (int i = 2; i < x / 2; i++)  // 如大于x/2有约数，则一定有一个小于x/2的对应
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
