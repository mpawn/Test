/*day10������
1.
дһ���������ز����������� 1 �ĸ���
���磺 15       0000 1111       4 �� 1
����ԭ�ͣ�
int  count_one_bits(unsigned int value)
{
       // ���� 1��λ��
}*/
#define _CRT_SECURE_NO_WARNINGS
int  count_one_bits(unsigned int input)
{
    int count =0;//������
    int i = 0;
        //32λ������unsigned int : 4���ֽ�
        //64λ������unsigned int : 4���ֽ�
        //4���ֽ�==32����λ==32������������
    for (i = 0; i < 32; i++)
    {
        //&����������2����λ��
        //>>���Ʋ��������ƶ����Ƕ�����λ
        //00000000000000000000000000000001  //1�Ķ�����
        //00000000000000000000000000001111  //15�Ķ�����
        //00000000000000000000000000000001  //(15>>0)&1�Ķ�����
        //00000000000000000000000000000111  //15>>1�Ķ�����
        //00000000000000000000000000000001  //(15>>1)&1�Ķ�����
        //����
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
    printf("������һ�����������ҽ������������������1�ĸ���:>\n");
    scanf("%u",&input);
    output = count_one_bits(input);
    printf("��������1�ĸ���Ϊ%u\n",output);
    return 0;
}
