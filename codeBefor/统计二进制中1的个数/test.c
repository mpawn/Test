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
    printf("������һ�������ҽ������������������1�ĸ���:>\n");
    scanf("%d", &input);
    output = count_bit_one(input);
    printf("��������1�ĸ���Ϊ%d\n", output);
    system("pause");
    return 0;
}