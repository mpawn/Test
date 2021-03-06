#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int count_bit_one(unsigned int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    int input = 0;
    int output = 0;
    printf("请输入一个数，我将返回这个数二进制中1的个数:>\n");
    scanf("%d", &input);
    output = count_bit_one(input);
    printf("二进制中1的个数为%d\n", output);
    system("pause");
    return 0;
}