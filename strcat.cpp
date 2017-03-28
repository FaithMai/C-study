/*strcat函数自己的实现*/
#include<iostream>
using namespace std;
void strcat(char *, char *);
int main()
{
	char a[20] = "one";
	char b[10] = "otherone";
	strcat(a, b);
	for (int i = 0; a[i] != NULL; i++)
		cout << a[i];
 	return 0;
}
 void strcat(char *str1, char *str2)
{
	while (*str1 != NULL)  // 让str1指向字符数组一的末尾
		str1++;
	while (*str2 != NULL)  // 将str2加在str1后面
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = NULL;
}