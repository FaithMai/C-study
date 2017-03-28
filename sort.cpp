/*选择排序法*/
#include<iostream>
using namespace std;
int main()
{
	int a[10], min, temp;
	cout << "please input 10 numbers:" << endl;
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for (int j = 0; j < 9; j++)  // 轮换的第一个数，逐渐往后面移动
	{
		min = j;
		for (int k = j + 1; k < 10; k++)
			if (a[min] >= a[k])
				min = k;
		temp = a[j];   // 将后方最小的值交换给轮换的第一个数
		a[j] = a[min];
		a[min] = temp;
	}
	cout << "Sort from small to large:" << endl;
	for (int i = 0; i < 10; i++)  // 用于数组的输出
		cout << a[i]<<" ";
}
/*冒泡排序法*/
#include<iostream>
using namespace std;
int main()
{
	int a[10], temp;
	cout << "please input 10 numbers:" << endl;
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for(int i = 9; i>1; i--)  // 外层的循坏，从a[0]开始，将最大的数放到末尾
		for(int j = 0; j < i; j++)		// 内层的循环，比较两个邻近的数，较大的放在后面
			if (a[j] >= a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	cout << "Sort from small to large:" << endl;
	for (int i = 0; i < 10; i++)  // 用于数组的输出
		cout << a[i] << " ";
	return 0;
}