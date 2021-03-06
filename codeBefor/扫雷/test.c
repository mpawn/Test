/*
相比V1.0，V2.0在更新了新特性
1.当输入坐标周围没有雷时，自动展开周围没有雷的坐标
2.第一次不炸死
3.由于自动展开的win记录过于复杂，所以废除win来记录是否获胜，改用IsWin函数来判断是否获胜
3.更加贴近真实扫雷体验
4.使排版更加合理
5.将三个文件合并成一个文件
6.加入了更多注释


将ROW（行数）后面的数字改为你想要的数字
将COL（列数）后面的数字改为你想要的数字
将EASY_COUNT （雷数）后面的数字改为你想要的数字


自动展开实现思路：展开的思想 - 递归
1.坐标不是雷
2.该坐标周围也没有雷
第一次不炸死实现思路：
如果第一次炸死，则重新布雷，goto到函数内部再次进行判断被不被炸死

*/
#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define EASY_COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void test();//test：描述游戏进行流程
void menu();//给用户提供游戏菜单
void game();//游戏的主程序：游戏的实现
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//初始化棋盘	
void DisplayBoard(char board[ROWS][COLS], int row, int col);//打印棋盘
void SetMine(char board[ROWS][COLS], int row, int col);//布置雷
void FindMine(char mind[ROWS][COLS], char show[ROWS][COLS], int row, int col);//扫雷
int get_mine_count(char board[ROWS][COLS], int x, int y);//计算（x，y）周围有几个雷
void update(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);//自动展开
int IsWin(char show[ROWS][COLS]);//赢了返回1，没赢返回0

//主函数调用test完成游戏测试
int main()
{
    test();
    return 0;
}

//test：描述游戏进行流程
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();//给用户提供游戏菜单
        printf("请选择:>\n");
        scanf("%d", &input);
        switch (input) {
        case 1:
            game();//游戏的主程序：游戏的实现
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

//给用户提供游戏菜单
void menu()
{
    printf("*********************************************\n");
    printf("*******     欢迎来到扫雷小游戏    ***********\n");
    printf("*******       1.play   0.exit     ***********\n");
    printf("*********************************************\n");
}

//游戏的主程序：游戏的实现
void game()
{
    //雷的信息存储
    //1.布置好的雷的信息；防止数组越界，数组扩大一圈
    char mine[ROWS][COLS] = { '0' };//11*11
    //2.存放排查出来的雷的信息，给玩家打印的数组；防止数组越界，数组扩大一圈
    char show[ROWS][COLS] = { '0' };

    InitBoard(mine, ROWS, COLS, '0');//初始化雷的棋盘
    InitBoard(show, ROWS, COLS, '*');//初始化给玩家看的棋盘
    DisplayBoard(show, ROW, COL);//打印给玩家看的棋盘
    //布置雷
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);//可用于观测雷的位置
    //扫雷
    FindMine(mine, show, ROW, COL);
}

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    //打印列号
    for (i = 0; i <= col; i++)
    {
        printf(" %d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf(" % d", i);//打印行号
        for (j = 1; j <= col; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;//雷的数量，可后期修改
    while (count)
    {
        int x = rand() % row + 1;//1-9
        int y = rand() % col + 1;//1-9
        if (board[x][y] == '0')
        {
            board[x][y] = '1';//字符1为雷
            count--;
        }
    }
}

//扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;//用户输入行坐标
    int y = 0;//用户输入列坐标
    int win = 0;////用户输入的次数
    //还可以输入的坐标个数：9*9-10=71
    while (!IsWin(show))
    {
        printf("请输入排查雷的坐标:>");
        scanf("%d%d", &x, &y);
    again:
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            //坐标合法
            //1.踩雷
            if (mine[x][y] == '1')
            {
                if (win == 0)//防止玩家第一次被炸死
                {
                    InitBoard(mine, ROWS, COLS, '0');//初始化雷的棋盘
                    SetMine(mine, ROW, COL);//重新布置雷
                    //DisplayBoard(mine, ROW, COL);//可用于观测雷的位置
                    goto again;//跳到重新判断新棋局(x,y)是否为雷，若为雷就再重新布置
                }
                printf("很遗憾，你被炸死了\n");
                DisplayBoard(mine, row, col);///打印雷的布局
                break;
            }
            else //不是雷
            {
                //计算（x，y）周围有几个雷
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                if (count == 0)
                {
                    update(mine, show, ROWS, COLS, x, y);//自动展开
                }
                DisplayBoard(show, row, col);

            }
        }
        else
        {
            printf("输入坐标非法，请重新输入!\n");
        }

    }
    if (IsWin(show))
    {
        printf("恭喜你排雷成功\n要不要再开一局？\n");
        DisplayBoard(mine, row, col);
        printf("\n");
        printf("\n");
        printf("\n");
    }
}

//计算（x，y）周围有几个雷
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    //解决char转int的数字问题
    //'1'-'0'=1
    //'3'-'0'=3
    return mine[x - 1][y] +
        mine[x - 1][y - 1] +
        mine[x][y - 1] +
        mine[x + 1][y - 1] +
        mine[x + 1][y] +
        mine[x + 1][y + 1] +
        mine[x][y + 1] +
        mine[x - 1][y + 1] - 8 * '0';
}

//自动展开
void update(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
    int i = 0;
    int j = 0;
    for (i = -1; i <= 1; i++)
    {
        j = -1;
        for (j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (!(x + i > 0 && x + i < ROWS && y + j>0 && y + j < COLS))
            {
                show[x + i][y + j] = '#';
                continue;
            }
            if (show[x + i][y + j] != '*' && show[x + i][y + j] != '#')
            {
                continue;
            }
            int count = get_mine_count(mine, x + i, y + j);
            if (count == 0 && show[x + i][y + j] == '*')
            {
                show[x + i][y + j] = count + '0';
                update(mine, show, ROWS, COLS, x + i, y + j);
            }
            else
            {
                show[x + i][y + j] = count + '0';
            }
        }
    }
    return;
}

int IsWin(char show[ROWS][COLS])
{
    int i = 0;
    int j = 0;
    int count = 0;
    for (i = 1; i <= ROW; i++)
    {
        j = 1;
        for (j = 1; j <= COL; j++)
        {
            if (show[i][j] == '*')
                count++;
        }
    }
    if (count == EASY_COUNT)
    {
        return 1;//赢了
    }
    else
    {
        return 0;//没赢
    }
}


