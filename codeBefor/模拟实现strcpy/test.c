#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)
{
    assert(dest != NULL);
    assert(src != NULL);
    char* ret = dest;
    //����srcָ����ַ�����destָ��Ŀռ䣬����'\0'
    while (*dest++ = *src++)
    {
        ;
    }
    //����Ŀ�Ŀռ����ʾ��ַ
    return ret;
}
int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "ghi";
    strcpy(arr1, arr2);
    printf("%s", arr1);
    return 0;
}