/*
13-01�������С���ʼ��԰棨The Biggest and Smallest Words�� 
��д�����ҳ�һ�鵥���С���С�����ʺ͡���󡱵��ʡ� 
�û����뵥�ʺ�,��������ֵ�˳�����������ǰ��������ĵ��ʡ� 
���û�����4����ĸ�ĵ���ʱ,����ֹͣ���롣
�������е��ʶ�������20����ĸ��
*/
/*strcmp������string compare(�ַ����Ƚ�)����д��
���ڰ�ASCIIֵ��С��Ƚ������ַ��������ݱȽϽ������������
������ʽΪstrcmp(str1,str2)
��str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 20
void sort(char a[], char b[])
{
    if (strcmp(a, b) == 0) {
        int i;
        for (i = 0; i <= (N + 1); i++) {
            if (a[i] < b[i])
                strcpy(b, a);
        }
    }
}

int main(void)
{
    char smallest_word[N + 1], largest_word[N + 1];
    char ch[N + 1];
    int i;

    printf("Enter word: ");
    scanf("%s", ch);
    strcpy(smallest_word, ch);
    strcpy(largest_word, ch);

    if (strlen(ch) == 4) {
        printf("Smallest word: %s\n", smallest_word);
        printf("Largest word: %s", largest_word);
        return 0;
    }
    for (;;) {
        printf("Enter word:");
        scanf("%s", ch);

        if (strcmp(ch, smallest_word) < 0)
            strcpy(smallest_word, ch);

        if (strcmp(ch, largest_word) > 0)
            strcpy(largest_word, ch);

        sort(ch, smallest_word);
        sort(ch, largest_word);

        if (strlen(ch) == 4)
            break;
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s", largest_word);
    return 0;
}
