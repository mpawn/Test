#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int DigitSum(unsigned int num)//1729
{
	if (num > 9)
	{
		return DigitSum(num / 10) + num % 10;//172+9//17+2+9//1+7+2+9
	}
	else
	{
		return num;
	}

}
int main()
{
	unsigned int num = 0;
	printf("����һ���Ǹ����������������������֮��:>\n");
	scanf("%d", &num);
	int ret = DigitSum(num);
	printf("ret=%d\n", ret);
}