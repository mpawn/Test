#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void print(int m)
{
	int i = 0;
	printf("����λ��\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
	printf("ż��λ��\n");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
}
//01010100010101000101010001010		1	 		0    		0
//                             ��������λ    �ڶ�ż��λ    ��һ����λ
int main()
{
	int m = 0;
	scanf("%d", &m);
	print(m);
	return 0;
}
