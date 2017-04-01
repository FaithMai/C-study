/*输入人数n，以n人围圈，一直报1,2,3，报到3的出局，场上只剩下一人游戏结束，输出是第几个人*/
#include<iostream>
using namespace std;
void circle(int a[], int *n, int *lastOne, int total) // a[]为传入的数组，n为场上的人数，m为最后一个人报的数字，total为人的总数
{
	int i = 0, m;
	m = *lastOne;
	while (i < total)  // 用于计数场上还剩下的人数
	{
		while (m < 4)
		{
			if (a[i] == 1 || a[i] == 2)  // 数字为1,2就更改本身的数
			{
				a[i] = m;
				m++;
			}
			else if(a[i] == 3)  // 数字为3，就改为0，代表退出循环
			{
				a[i] = 0;
				(*n)--;  // 注意这里要先取值，再自减
			}
			i++;  // 数字为0，会直接跳过，其他数字也会执行本语句，代表往后一位
			if (i == total)
				break;
		}
		*lastOne = m;
		m = 1;
	}
}
int main()
{
	int a[20], theLastOne, n,total, k;
	cout << "please input the number of people" << endl;
	cin >> n;
	for (int i = 0; i < n; i += 3)  // 用于每个人的初始复制
		for (int j = 1; j < 4; j++)
			a[i + j - 1] = j;
	theLastOne = a[n - 1];
	total = n;
	while (n > 1)
	{
		circle(a, &n, &theLastOne, total);
		if (n == 1)  // 当场上只剩下一个人时，输出
		{
			for (k = 0; k < total; k++)
			{
				if (a[k] != 0)
					break;
			}
			cout << "the one is at " << k + 1 << endl;
		}
	}
	return 0;
}