/*
12-01 (a)：逆序（Reversal） 编写程序读一条消息，然后逆序打印出这条消息。

输出范例：

Enter a message: Don't get mad, get even.
Reversal is: .neve teg ,dam teg t'noD

Enter a message: Hello, world!
Reversal is: !dlrow ,olleH

提示：⼀次读取消息中的⼀个字符（⽤getchar函数），并且把这些字符存储在数组中，当数组写满或者读到字符 '\n' 时停⽌读⼊。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char Input[512] = {0}; //用来容纳初始输入数据的字符数组
	char Output[512] = {0}; //存放反转字符串的数组
	int Len = 0; //记录初始字串长度
	int i = 0;

	printf("Enter a message: ");

	gets(Input); //从标准输入读取字串abcd

	Len = strlen(Input);//4

	//直接利用数组变量(其实它就是一个指针变量)来反转字串
	for (i = 0; i < Len; i++)//4
	{
		*(Output + Len - i-1) = *(Input + i);
	}

	Output[Len] = '\0'; //补上结尾的0

	printf("Reversal is:%s", Output);

	return 0;
}