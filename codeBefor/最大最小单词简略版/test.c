/*
13-01：最大最小单词简略版（The Biggest and Smallest Words） 
编写程序找出一组单词中“最小”单词和“最大”单词。 
用户输入单词后,程序根据字典顺序决定排在最前面和最后面的单词。 
当用户输入4个字母的单词时,程序停止读入。
假设所有单词都不超过20个字母。
*/
/*strcmp函数是string compare(字符串比较)的缩写，
用于按ASCII值大小相比较两个字符串并根据比较结果返回整数。
基本形式为strcmp(str1,str2)
若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数
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
