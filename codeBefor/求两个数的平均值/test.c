/*2.不使用（a + b） / 2这种方式，求两个数的平均值。*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("请输入两个数，程序返回平均值:>\n");
	int a = 0;
	int b = 0;
	scanf("%d%d",&a,&b);
	//用a和b相同的部分加上a和b不同的地方，a和b相同的部分为（a&b），a和b不同的部分为（a^b），不同的部分除以二就是（a^b>>1）
	printf("%d\n", (a & b) + ((a ^ b) >> 1));
	return 0;
}