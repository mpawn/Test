递归和非递归分别实现strlen

//非递归官方函数版本
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int strSize=0;
	char str[100] = { 0 };
	printf("请输入一串字符串，本程序会将求出字符串的长度:>");
	gets(str);
	strSize=strlen(str);
	printf("%d",strSize);
	return 0;
}

//非递归自制函数版本
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int selfStrlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}

int main()
{
	int strSize = 0;
	char str[100] = { 0 };
	printf("请输入一串字符串，本程序会将求出字符串的长度:>");
	gets(str);
	strSize = selfStrlen(str);
	printf("%d", strSize);
	return 0;
}

//递归自制函数版本
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int selfStrlen(char* str)
{
	int sum = 0;
	if(*str == '\0')
	{
		return 0;
	}//跳出递归，当数组为字符串结束标志的时候跳出递归
	sum += 1;
	sum +=selfStrlen(str + 1);
	return sum;
}
//abcd

int main()
{
	int strSize = 0;
	char str[100] = { 0 };
	printf("请输入一串字符串，本程序会将求出字符串的长度:>");
	gets(str);
	strSize = selfStrlen(str);
	printf("%d", strSize);
	return 0;
}