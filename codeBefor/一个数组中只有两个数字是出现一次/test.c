/*
1.一个数组中只有两个数字是出现一次，
其他所有数字都出现了两次。
找出这两个只出现一次的数字，编程实现。
*/
#include<stdio.h>
#include<windows.h>

void Find(int arr[], int len)
{
	int num1 = 0;
	int num2 = 0;
	int ret = 0;
	int n = 0;
	int i = 0;
	int bit = 0;
	//1, 2, 3, 3, 2, 1, 4, 5 
	//两个相同的数异或的结果是0
	//所有不为0的数和0异或的结果是本身
	//0^遍历数组，得到ret=4^5
	for (i = 0; i < len; i++)
	{
		ret = ret ^ arr[i];
	}
	//一个数&1，得到这个数二进制位的最后一位的数字
	for (n = 0; n < 32; n++)
	{
		//如果4^5从后向前数第n+1位为1则跳出
		//4-100
		//5-101
		//4^5-001
		//n=0
		if (((ret >> n) & 1) == 1)
			break;
	}

	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> n) & 1 )== 1)
			//最后一位为1的
			num1 = num1 ^ arr[i];
		else
			//最后一位不为1的
			num2 = num2 ^ arr[i];
	}
	printf(" num1=%d\n num2=%d\n", num1, num2);
}


void main()
{
	int a[] = { 1, 2, 3, 3, 2, 1, 4, 5 };
	int len = sizeof(a) / sizeof(a[0]);
	Find(a, len);
	system("pause");
	return 0;
}


/*
1.一个数组中只有一个数字是出现一次，
其他所有数字都出现了两次。
找出这一个只出现一次的数字，编程实现。

#include<stdio.h>
int main()
{
	int arr[] = { 1,1,2,2,3,3,4};
	int i = 0;
	int ret = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		ret = ret ^ arr[i];
	}
	//0^n	异或：相同为0，相异为1
	//0^(0^n)  ==  0
	printf("%d",ret);
	return 0;
}
*/