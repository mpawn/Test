�ݹ�ͷǵݹ�ֱ�ʵ��strlen

//�ǵݹ�ٷ������汾
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int strSize=0;
	char str[100] = { 0 };
	printf("������һ���ַ�����������Ὣ����ַ����ĳ���:>");
	gets(str);
	strSize=strlen(str);
	printf("%d",strSize);
	return 0;
}

//�ǵݹ����ƺ����汾
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
	printf("������һ���ַ�����������Ὣ����ַ����ĳ���:>");
	gets(str);
	strSize = selfStrlen(str);
	printf("%d", strSize);
	return 0;
}

//�ݹ����ƺ����汾
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int selfStrlen(char* str)
{
	int sum = 0;
	if(*str == '\0')
	{
		return 0;
	}//�����ݹ飬������Ϊ�ַ���������־��ʱ�������ݹ�
	sum += 1;
	sum +=selfStrlen(str + 1);
	return sum;
}
//abcd

int main()
{
	int strSize = 0;
	char str[100] = { 0 };
	printf("������һ���ַ�����������Ὣ����ַ����ĳ���:>");
	gets(str);
	strSize = selfStrlen(str);
	printf("%d", strSize);
	return 0;
}