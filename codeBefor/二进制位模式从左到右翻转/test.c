/*
1.��д������
unsigned int reverse_bit(unsigned int value);
��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��

�磺
��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001
��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�
          2550136832
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

unsigned int power(int n,int m)//ʵ��n��m�η�
{
    int sum = n;
    int i = 0;
    if (m == 0)
    {
        return 1;
    }
    for (i = 0; i < m-1; i++)
    {
        sum = sum * n;
    }
    return sum;
}

unsigned int reverse_bit(unsigned int value)
{
    unsigned int output = 0;
    int arr[32] = { 0 };
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        if (1 == ((value >> i) & 1))
        {
            arr[i] = 1;
        }
    }
    
    int j = 0;
    for (i = 0, j = 31; i < 32; i++)
    {
        output += arr[i] * power(2, j);
        j--;
    }
    /*
    0 31
    1 30
    2 29
    ......
    31 0
    */
    return output;
}

int main()
{
    unsigned int input = 0;
    scanf("%u", &input);
    unsigned int output =reverse_bit(input);
    printf("%u", output);
    return 0;
}