//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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
	printf("������һ�������������򽫴�ӡһ��������ÿһλ:>");
	scanf("%d", &n);
	print(n);
	system("pause");
	return 0;
}