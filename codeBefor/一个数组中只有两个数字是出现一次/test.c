/*
1.һ��������ֻ�����������ǳ���һ�Σ�
�����������ֶ����������Ρ�
�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
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
	//������ͬ�������Ľ����0
	//���в�Ϊ0������0���Ľ���Ǳ���
	//0^�������飬�õ�ret=4^5
	for (i = 0; i < len; i++)
	{
		ret = ret ^ arr[i];
	}
	//һ����&1���õ������������λ�����һλ������
	for (n = 0; n < 32; n++)
	{
		//���4^5�Ӻ���ǰ����n+1λΪ1������
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
			//���һλΪ1��
			num1 = num1 ^ arr[i];
		else
			//���һλ��Ϊ1��
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
1.һ��������ֻ��һ�������ǳ���һ�Σ�
�����������ֶ����������Ρ�
�ҳ���һ��ֻ����һ�ε����֣����ʵ�֡�

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
	//0^n	�����ͬΪ0������Ϊ1
	//0^(0^n)  ==  0
	printf("%d",ret);
	return 0;
}
*/