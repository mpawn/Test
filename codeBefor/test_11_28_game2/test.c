#include "game.h"
void menu()
{
    printf("**************************************\n");
    printf("*******     1.play    ****************\n");
    printf("*******     0.exit    ****************\n");
    printf("**************************************\n");
}

void game()
{
    //雷的信息存储
    //1.布置好的雷的信息；防止数组越界，数组扩大一圈
    char mine[ROWS][COLS] = { '0' };//11*11
    //2.存放排查出来的雷的信息，给玩家打印的数组；防止数组越界，数组扩大一圈
    char show[ROWS][COLS] = { '0' };
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    DisplayBoard(show, ROW, COL);
    //布置雷
    SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);//可用于观测雷的位置
    //扫雷
    FindMine(mine, show, ROW, COL);
}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>\n");
        scanf("%d", &input);
        switch (input) {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误,请重新选择!:>");
            break;
        }
    } while (input);
}

int main()
{
    test();
    return 0;
}

