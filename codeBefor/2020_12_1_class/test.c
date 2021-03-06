//递归和非递归分别实现求n的阶乘
//阶乘:一个非负整数n的阶乘是所有小于或等于 n的正整数之积 

非递归实现求n的阶乘
*#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Factorial(int n)
{
	int answer = 1;
	int i = n;
	for (i = n; i > 0; i--)
	{
		answer *= i;
	}
	return answer;
}

int main()
{
	int n = 0;
	int answer = 0;
	printf("请输入一个数，本程序会返回这个数的阶乘:>");
	scanf("%d",&n);
	answer = Factorial(n);
	printf("%d",answer);
	return 0;
}

递归实现求n的阶乘
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Factorial(int n)//3
{
	int out;
	if (n == 1)
	{
		return 1;
	}
	out = n * Factorial(n-1);
	return out;
}

int main()
{
	int n = 0;
	int answer = 0;
	printf("请输入一个数，本程序会返回这个数的阶乘:>");
	scanf("%d", &n);
	answer = Factorial(n);
	printf("%d", answer);
	return 0;
}






