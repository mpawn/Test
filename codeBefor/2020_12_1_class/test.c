//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//�׳�:һ���Ǹ�����n�Ľ׳�������С�ڻ���� n��������֮�� 

�ǵݹ�ʵ����n�Ľ׳�
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
	printf("������һ������������᷵��������Ľ׳�:>");
	scanf("%d",&n);
	answer = Factorial(n);
	printf("%d",answer);
	return 0;
}

�ݹ�ʵ����n�Ľ׳�
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
	printf("������һ������������᷵��������Ľ׳�:>");
	scanf("%d", &n);
	answer = Factorial(n);
	printf("%d", answer);
	return 0;
}






