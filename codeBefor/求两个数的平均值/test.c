/*2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("�����������������򷵻�ƽ��ֵ:>\n");
	int a = 0;
	int b = 0;
	scanf("%d%d",&a,&b);
	//��a��b��ͬ�Ĳ��ּ���a��b��ͬ�ĵط���a��b��ͬ�Ĳ���Ϊ��a&b����a��b��ͬ�Ĳ���Ϊ��a^b������ͬ�Ĳ��ֳ��Զ����ǣ�a^b>>1��
	printf("%d\n", (a & b) + ((a ^ b) >> 1));
	return 0;
}