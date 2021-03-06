#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void menu()
{
    printf("*********************\n");
    printf("1:add            2:sub\n");
    printf("3:mul            4:div\n");
    printf("0.exit                  \n");
    printf("*********************\n");
}

int Add(int a, int b)
{
    return a + b;
}
int Sub(int a, int b)
{
    return a - b;
}
int Mul(int a, int b)
{
    return a * b;
}
int Div(int a, int b)
{
    return a / b;
}

int main()
{
    int x, y;
    int input = 1;
    int ret = 0;
    int(*pfArr[5])(int x, int y) = { 0, Add, Sub, Mul, Div }; //函数指针数组：转移表
    while (input)
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        if ((input <= 4 && input >= 1))
        {
            printf("输入操作数：");
            scanf("%d %d", &x, &y);
            ret = pfArr[input](x, y);
            printf("%d\n", ret);
        }
        else if (input == 0)
        {
            printf("退出");
        }
        else
        {
            printf("选择错误");
        }
        return 0;
    }
}