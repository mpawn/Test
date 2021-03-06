/*day10操作符
1.
写一个函数返回参数二进制中 1 的个数
比如： 15       0000 1111       4 个 1
程序原型：
int  count_one_bits(unsigned int value)
{
       // 返回 1的位数
}*/
#define _CRT_SECURE_NO_WARNINGS
int  count_one_bits(unsigned int input)
{
    int count =0;//计数器
    int i = 0;
        //32位编译器unsigned int : 4个字节
        //64位编译器unsigned int : 4个字节
        //4个字节==32比特位==32个二进制数字
    for (i = 0; i < 32; i++)
    {
        //&操作符：按2进制位与
        //>>右移操作符：移动的是二进制位
        //00000000000000000000000000000001  //1的二进制
        //00000000000000000000000000001111  //15的二进制
        //00000000000000000000000000000001  //(15>>0)&1的二进制
        //00000000000000000000000000000111  //15>>1的二进制
        //00000000000000000000000000000001  //(15>>1)&1的二进制
        //……
        if (1 == ((input >> i) & 1))
        count++;
    }
    return count;
}
#include<stdio.h>
int main()
{
    unsigned int input = 0;
    unsigned int output = 0;
    printf("请输入一个正整数，我将返回这个数二进制中1的个数:>\n");
    scanf("%u",&input);
    output = count_one_bits(input);
    printf("二进制中1的个数为%u\n",output);
    return 0;
}
