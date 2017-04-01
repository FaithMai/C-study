/*用于4行5列的二维数组中，值是否为行最大列最小判断和输出*/
#include<iostream>
using namespace std;
int main()
{
	int a[4][5], maxRow[4], totalSaddle = 0;
	bool column = false;
	cout << "please input number:" << endl;
	for (int i = 0; i < 4; i++)  // 输入4行5列数据
	{
		for (int j = 0; j < 5; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < 4; i++)  // 找出每一行的最大值所在列
	{
		maxRow[i] = 0;
		for (int j = 1; j < 5; j++)
		{
			if (a[i][maxRow[i]] < a[i][j])
				maxRow[i] = j;
		}
	}
	for (int i = 0; i < 4; i++)  // 为了调出maxRow
	{
		for (int j = 0; j < 4; j++)  // 进行最大值所在列的列查找
		{
			if (a[i][maxRow[i]] <= a[j][maxRow[i]])  // 用于最大值所在列的判断
				column = true;
			else  // 如果大于其他值就跳出循环
			{
				column = false;
				break;
			}
		}
		if (column)  // 用于"有鞍点"字符串输出的控制
			totalSaddle++;
		if ((totalSaddle == 1) && (column == true))
			cout << "有鞍点:" << endl;
		if (column)
			cout << a[i][maxRow[i]] << endl;
	}
	if (!totalSaddle)
		cout << "无鞍点" << endl;
	return 0;
}