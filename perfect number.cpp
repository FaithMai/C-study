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



/*另一种实现方法，用两次for循环，但是要注意的是因子并不是所有的乘积，而更接近于能乘除的因子的乘积（只是接近）*/
#include<iostream>
using namespace std;
int main()
{
	int array[30] = { 0 };  // 用于存储完数的每一项值,数组大小要注意，因为求因子，即能被整除就可行，所以要大些。如30因子包括1、2、3、5、6、10、15
	int i, j, total, num;
	for (i = 2; i <= 1000; i++)  // 完数不包括1，从2开始循环
	{
		num = 0;  // 用于记录数组下标
		total = 0;
		for (j = 2; j < i; j++)  // 也从2开始循环，目的是为了让后面单独输出一个1
		{
			if ((i%j) == 0)
			{
				array[num] = j;
				num++;
				total += j;  // 对因子求和
			}
		}
		if ((total+1) == i)  // 加一是因为排除了1
		{
			cout << i << "，its factors are " << 1;  
			for (int k = 0; k < num; k++)
				cout << "，" << array[k];
			cout << endl;
		}
		
	}
	return 0;
}