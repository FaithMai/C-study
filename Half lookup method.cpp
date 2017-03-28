/*折半查找法，使用条件：在排好序的数列中进行使用，通过手动修改数组长度和right的值*/
#include<iostream>
using namespace std;
int main()
{
	int a[16] = { 1,12,13,45,56,78,89,96,97,99,101,120,121,122,123,144 };
	int lookfor, i, j, left = 0, right = 15;
	if (right % 2 == 0)
	{
		i = (right - 1) / 2;
		j = (right + 1) / 2;
	}
	else
		i = j = right / 2;
	i = j = right / 2;
	cout << "please input a numnber:" << endl;
	scanf("%d", &lookfor);
	while (right-left >= 1)  // 判断中间值
	{
		if (a[i] == lookfor)  // 中间值取得目标值的时候输出
		{
			cout << "the number is at " << i + 1;
			break;
		}                        
		else if (a[j] == lookfor)
		{
			cout << "the number is at " << j+1;
			break;
		}						// 当包括两端时总为偶数个数
		else if (a[i] > lookfor)   // 当目标值比左侧的中间值更小时
		{
			right = i;
			i = (i + left - 1) / 2;
			j = (i + left + 1) / 2;
		}
		else if (a[j] < lookfor)  // 当目标值比右侧的中间值更大时
		{
			left = j;
			i = (j + right - 1) / 2;
			j = (j + right + 1) / 2;
		}
	}
	if (right - left < 1)
		cout << "number inexist" << endl;
	return 0;
}