
2.
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
嫌疑犯的一个。以下为4个嫌疑犯的供词。
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。

#include <stdio.h>
int main()
{
    //以此假设凶手是ABCD
    int killer = 0;
    for (killer = 'a'; killer <= 'd'; killer++)
    {
        //将每个人的话当成一个条件
        //正确是1，不正确为0
        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
        {
            printf("killer = %c\n", killer);
        }
    }
    return 0;
}