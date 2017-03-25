#include <iostream>
using namespace std;
//第一个塔为初始塔，中间的塔为借用塔，最后一个塔为目标塔 
void move(char from, char to) //将编号为n的盘子由from移动到to  
{
	cout << from << "--->" << to << endl;
}
void hanoi(int n, char from, char denpend_on, char to)  // 将n个盘子由初始塔移动到目标塔(利用借用塔)  
{
	if (n == 1)
		move(from, to);  // 只有一个盘子是直接将初塔上的盘子移动到目的地  
	else
	{
		hanoi(n - 1, from, to, denpend_on);  // 先将初始塔的前n-1个盘子借助目的塔移动到借用塔上  
		move(from, to);              // 将剩下的一个盘子移动到目的塔上  
		hanoi(n - 1, denpend_on, from, to);  // 最后将借用塔上的n-1个盘子移动到目的塔上  
	}
}
int main()
{
	cout << "请输入盘子的个数:" << endl;
	int n;
	cin >> n;
	char x = 'A', y = 'B', z = 'C';
	cout << "盘子移动情况如下:"<< endl;
	hanoi(n, x, y, z);
	return 0;
}
/*有3个柱子A,B,C
初始情况在柱子A上，最终转移到C上。可以通过2个盘子开始考虑:
要将两个盘子移动过去，首先要将上面一个盘子借助C移动到B，使得下面的盘子上无盘子。在将两个盘子移动过去就行。
考虑三个盘子，由于A柱子被占用，C柱在最终时刻不能被占用，所以要先通过C将除了最下面的盘子移动到B，
此时B上有两个盘子，再借助C柱子将上面的盘子移动到A，之后就很容易了。
推导:当为4个盘子时，实质可以理解为3的倒数第2步移动到A柱子上有两个盘子，情况就回到了初始的情况，
由A到C，使得代码成为可能，不断重复。当盘子无限多的时候，在逻辑上进行这样的推导，最终推出最上方盘子的移动方式（就是递归运算），使得移动方式被解出来。*/