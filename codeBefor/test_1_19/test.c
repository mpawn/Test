#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c; // ע�⣺int����char��Ҫ����EOF
    FILE* fp = fopen("test.txt", "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;//stdlib.h����#define EXIT_FAILURE 1
    }
    //fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
    while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
    {
        putchar(c);
    }

    //�ж���ʲôԭ�������
    if (ferror(fp))//���fp��û�з�������ferror������0��������������һ������ֵ
        puts("I/O error when reading");
    else if (feof(fp))
        //feof�����ڵ�һ�ζ�ȡ�����󷵻�һ������ֵ��
        //�ò�����ͼ��ȡ�ļ���ĩβ��
        //�����ǰλ�ò����ļ���β���򷵻�0
        puts("End of file reached successfully");

    fclose(fp);
}