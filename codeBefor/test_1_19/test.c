#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c; // 注意：int，非char，要求处理EOF
    FILE* fp = fopen("test.txt", "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;//stdlib.h中有#define EXIT_FAILURE 1
    }
    //fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
    while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
    {
        putchar(c);
    }

    //判断是什么原因结束的
    if (ferror(fp))//如果fp中没有发生错误，ferror将返回0。否则，它将返回一个非零值
        puts("I/O error when reading");
    else if (feof(fp))
        //feof函数在第一次读取操作后返回一个非零值，
        //该操作试图读取文件的末尾。
        //如果当前位置不是文件结尾，则返回0
        puts("End of file reached successfully");

    fclose(fp);
}