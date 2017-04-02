/*输入年月日，判断是第几天，以前看到的一个实现方法，是目前看到的最简的方法，现在实现一下*/
#include<iostream>
using namespace std;
struct day {
	unsigned int year;
	unsigned int month;
	unsigned int today;
};
bool judgeBissextile(day oneday)  // 判断是否为瑞年的函数
{
	if ((oneday.year % 4 == 0 && oneday.year % 100 != 0) || oneday.year % 400 == 0)
		return true;
	else
		return false;
}
int totalDay(day oneday) // 1.3.5.7.8.10.12
{
	int total = 0;
	switch (oneday.month)  // 直接计算当是瑞年的时候，是第几天
	{
		case 12:total += 30;  // 选12月则加上11月的30天，之后再加10月等
		case 11:total += 31;
		case 10:total += 30;
		case 9:total += 31;
		case 8:total += 31;
		case 7:total += 30;
		case 6:total += 31;
		case 5:total += 30;
		case 4:total += 31;
		case 3:total += 29;
		case 2:total += 31;
	}
	total += oneday.today;
	if (!judgeBissextile(oneday) && oneday.month > 2)  // 当不是瑞年，并且月份大于2的时候，总天数减一
		total--;
	return total;
}
int main()
{
	day one;
	cout << "please input year month day:" << endl;
	cin >> one.year >> one.month >> one.today;
	cout << "是第" << totalDay(one) << "天" << endl;
}