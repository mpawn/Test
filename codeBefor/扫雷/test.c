/*
���V1.0��V2.0�ڸ�����������
1.������������Χû����ʱ���Զ�չ����Χû���׵�����
2.��һ�β�ը��
3.�����Զ�չ����win��¼���ڸ��ӣ����Էϳ�win����¼�Ƿ��ʤ������IsWin�������ж��Ƿ��ʤ
3.����������ʵɨ������
4.ʹ�Ű���Ӻ���
5.�������ļ��ϲ���һ���ļ�
6.�����˸���ע��


��ROW����������������ָ�Ϊ����Ҫ������
��COL����������������ָ�Ϊ����Ҫ������
��EASY_COUNT ����������������ָ�Ϊ����Ҫ������


�Զ�չ��ʵ��˼·��չ����˼�� - �ݹ�
1.���겻����
2.��������ΧҲû����
��һ�β�ը��ʵ��˼·��
�����һ��ը���������²��ף�goto�������ڲ��ٴν����жϱ�����ը��

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
void test();//test��������Ϸ��������
void menu();//���û��ṩ��Ϸ�˵�
void game();//��Ϸ����������Ϸ��ʵ��
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//��ʼ������	
void DisplayBoard(char board[ROWS][COLS], int row, int col);//��ӡ����
void SetMine(char board[ROWS][COLS], int row, int col);//������
void FindMine(char mind[ROWS][COLS], char show[ROWS][COLS], int row, int col);//ɨ��
int get_mine_count(char board[ROWS][COLS], int x, int y);//���㣨x��y����Χ�м�����
void update(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);//�Զ�չ��
int IsWin(char show[ROWS][COLS]);//Ӯ�˷���1��ûӮ����0

//����������test�����Ϸ����
int main()
{
    test();
    return 0;
}

//test��������Ϸ��������
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();//���û��ṩ��Ϸ�˵�
        printf("��ѡ��:>\n");
        scanf("%d", &input);
        switch (input) {
        case 1:
            game();//��Ϸ����������Ϸ��ʵ��
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("ѡ�����,������ѡ��!:>");
            break;
        }
    } while (input);
}

//���û��ṩ��Ϸ�˵�
void menu()
{
    printf("*********************************************\n");
    printf("*******     ��ӭ����ɨ��С��Ϸ    ***********\n");
    printf("*******       1.play   0.exit     ***********\n");
    printf("*********************************************\n");
}

//��Ϸ����������Ϸ��ʵ��
void game()
{
    //�׵���Ϣ�洢
    //1.���úõ��׵���Ϣ����ֹ����Խ�磬��������һȦ
    char mine[ROWS][COLS] = { '0' };//11*11
    //2.����Ų�������׵���Ϣ������Ҵ�ӡ�����飻��ֹ����Խ�磬��������һȦ
    char show[ROWS][COLS] = { '0' };

    InitBoard(mine, ROWS, COLS, '0');//��ʼ���׵�����
    InitBoard(show, ROWS, COLS, '*');//��ʼ������ҿ�������
    DisplayBoard(show, ROW, COL);//��ӡ����ҿ�������
    //������
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);//�����ڹ۲��׵�λ��
    //ɨ��
    FindMine(mine, show, ROW, COL);
}

//��ʼ������
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

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    //��ӡ�к�
    for (i = 0; i <= col; i++)
    {
        printf(" %d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf(" % d", i);//��ӡ�к�
        for (j = 1; j <= col; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

//������
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;//�׵��������ɺ����޸�
    while (count)
    {
        int x = rand() % row + 1;//1-9
        int y = rand() % col + 1;//1-9
        if (board[x][y] == '0')
        {
            board[x][y] = '1';//�ַ�1Ϊ��
            count--;
        }
    }
}

//ɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;//�û�����������
    int y = 0;//�û�����������
    int win = 0;////�û�����Ĵ���
    //��������������������9*9-10=71
    while (!IsWin(show))
    {
        printf("�������Ų��׵�����:>");
        scanf("%d%d", &x, &y);
    again:
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            //����Ϸ�
            //1.����
            if (mine[x][y] == '1')
            {
                if (win == 0)//��ֹ��ҵ�һ�α�ը��
                {
                    InitBoard(mine, ROWS, COLS, '0');//��ʼ���׵�����
                    SetMine(mine, ROW, COL);//���²�����
                    //DisplayBoard(mine, ROW, COL);//�����ڹ۲��׵�λ��
                    goto again;//���������ж������(x,y)�Ƿ�Ϊ�ף���Ϊ�׾������²���
                }
                printf("���ź����㱻ը����\n");
                DisplayBoard(mine, row, col);///��ӡ�׵Ĳ���
                break;
            }
            else //������
            {
                //���㣨x��y����Χ�м�����
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                if (count == 0)
                {
                    update(mine, show, ROWS, COLS, x, y);//�Զ�չ��
                }
                DisplayBoard(show, row, col);

            }
        }
        else
        {
            printf("��������Ƿ�������������!\n");
        }

    }
    if (IsWin(show))
    {
        printf("��ϲ�����׳ɹ�\nҪ��Ҫ�ٿ�һ�֣�\n");
        DisplayBoard(mine, row, col);
        printf("\n");
        printf("\n");
        printf("\n");
    }
}

//���㣨x��y����Χ�м�����
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    //���charתint����������
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

//�Զ�չ��
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
        return 1;//Ӯ��
    }
    else
    {
        return 0;//ûӮ
    }
}


