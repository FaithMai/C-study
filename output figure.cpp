/*输出了一个菱形*/
#include<iostream>
using namespace std;
int main()
{
	int total;   // 思路，由于图形与矩形相似，可认为是分别输出*和空格
	for (total = 3; total > 0; total--)  // 用于上面三排的输出
	{
		for (int i = 0; i < total; i++)  //输出空格
			cout << '\0';
		for (int i = 0; i < (3-total)*2+1; i++)  // 输出中间的*
			cout << '*';
		for (int i = 0; i < total; i++)  // 输出空格
			cout << '\0';
		cout << endl;
	}
	for (total=0; total < 4; total++)  // 用于后四排的输出
	{
		for (int i = 0; i < total; i++)
			cout << '\0';
		for (int i = 0; i < (3 - total) * 2 + 1; i++)
			cout << '*';
		for (int i = 0; i < total; i++)
			cout << '\0';
		cout << endl;
	}


	return 0;
}