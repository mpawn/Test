/*day07
4. ��дһ������ reverse_string(char* string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�
Ҫ�󣺲���ʹ��C�������е��ַ�������������*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void reverse_string(char* string)//�ַ�������Ԫ�صĵ�ַ
{
    if (*string == '\0')//��Ԫ��Ϊ�ַ��������ı�־
    {
        return;
    }//�����ݹ������
    reverse_string(string + 1);
    printf("%c", *string);
}

int main()
{
    char str[100] = { 0 };
    printf("������һ���ַ���������ʵ�ֽ��ַ���������Ȼ�����:>");
    gets(str);//�����û�������ַ���
    reverse_string(str);
    return 0;
}