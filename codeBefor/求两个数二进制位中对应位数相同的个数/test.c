#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int count_bit_one(unsigned int n)//求一个二进制中有几个1
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int git_diff(int m, int n)
{
    int tmp = m ^ n;//相同返回1，不同返回0
    int count = 0;
    count = count_bit_one(tmp);
    return count;
}
//^ 操作符：按2进制位异或（相同为0，相异为1）
//int a = 3;
//int b = 5;
//int c = a ^ b;//6
//a:011
//b:101
//c:110         
int main()
{
    int m = 0;
    int n = 0;
    printf("请输入两个数，我将求这两个整数的二进制表达中， 有多少个位(bit)不同：>\n");
    scanf("%d%d", &m, &n);
    int count = git_diff(m, n);
    printf("%d", count);
}