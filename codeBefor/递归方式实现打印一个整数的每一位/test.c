//递归方式实现打印一个整数的每一位
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<Windows.h>
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int n = 521;
	printf("请输入一个整数，本程序将打印一个整数的每一位:>");
	scanf("%d", &n);
	print(n);
	system("pause");
	return 0;
}