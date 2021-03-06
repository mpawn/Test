/*day07
4. 编写一个函数 reverse_string(char* string)（递归实现）
实现：将参数字符串中的字符反向排列。
要求：不能使用C函数库中的字符串操作函数。*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void reverse_string(char* string)//字符数组首元素的地址
{
    if (*string == '\0')//首元素为字符串结束的标志
    {
        return;
    }//跳出递归的条件
    reverse_string(string + 1);
    printf("%c", *string);
}

int main()
{
    char str[100] = { 0 };
    printf("请输入一串字符串，程序将实现将字符反向排列然后输出:>");
    gets(str);//接受用户输入的字符串
    reverse_string(str);
    return 0;
}