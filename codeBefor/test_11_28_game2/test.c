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
    //�׵���Ϣ�洢
    //1.���úõ��׵���Ϣ����ֹ����Խ�磬��������һȦ
    char mine[ROWS][COLS] = { '0' };//11*11
    //2.����Ų�������׵���Ϣ������Ҵ�ӡ�����飻��ֹ����Խ�磬��������һȦ
    char show[ROWS][COLS] = { '0' };
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    DisplayBoard(show, ROW, COL);
    //������
    SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);//�����ڹ۲��׵�λ��
    //ɨ��
    FindMine(mine, show, ROW, COL);
}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("��ѡ��:>\n");
        scanf("%d", &input);
        switch (input) {
        case 1:
            game();
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

int main()
{
    test();
    return 0;
}

