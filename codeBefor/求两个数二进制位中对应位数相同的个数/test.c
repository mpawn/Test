#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int count_bit_one(unsigned int n)//��һ�����������м���1
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
    int tmp = m ^ n;//��ͬ����1����ͬ����0
    int count = 0;
    count = count_bit_one(tmp);
    return count;
}
//^ ����������2����λ�����ͬΪ0������Ϊ1��
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
    printf("���������������ҽ��������������Ķ����Ʊ���У� �ж��ٸ�λ(bit)��ͬ��>\n");
    scanf("%d%d", &m, &n);
    int count = git_diff(m, n);
    printf("%d", count);
}