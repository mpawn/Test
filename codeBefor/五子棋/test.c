#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 12
#define COL 12

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����
void test();
void menu();
void game();
void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������
void DisplayBoard(char board[ROW][COL], int row, int col);//��ӡ����
void PlayerMove(char board[ROW][COL], int row, int col);//�������
void ComputerMove(char board[ROW][COL], int row, int col);//��������
char IsWin(char board[ROW][COL], int row, int col);//�ж��Ƿ�Ӯ�����
int IsFull(char board[ROW][COL], int row, int col);//�ж��Ƿ����

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
		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("������\n");
			game();//��Ϸ��������
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			break;
		}
	} while (input);
}





//��Ϸ�˵�
void menu()
{
	printf("######################################\n");
	printf("#####    ��ӭ������������Ϸ    #######\n");
	printf("#####    1.play      0.exit    #######\n");
	printf("######################################\n");
}

��Ϸ����������Ϸ��ʵ��;
void game()
{
	//����һ�����飺����߳���������Ϣ
	char board[ROW][COL] = { '0' };//ȫ���ո�
	//Ϊ���Ժ�����M*N���壬�Ժ��ڶ�����ֱ���޸ľͿ���ʵ��
	char ret = 0;

	//��ʼ������
	InitBoard(board, ROW, COL);	//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)//��ҵ���������
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//��ӡ��������ҿ�
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);//�ж���Ϸ����������� * ���Ӯ  #����Ӯ   Qƽ��  C������
		if (ret != 'C')//���ƽ�ֻ�һ����ʤ���͵���
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//��ӡ��������ҿ�
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//�����������ϵ�'0'ȫ�����Ϊ�ո�' '
		}
	}
}

//��ӡ����
//������ӡ��������ӣ�
//   |   |
//---|---|---
//   |   |
//---|---|---
//   |   |
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ�к�
	for (i = 1; i <= col; i++)
	{
		printf(" %d  ", i);
	}
	printf("\n");
	for (i = 0; i < row; i++)//�����д�ӡ����
	{
		//1.��ӡһ�е�����
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");//����
		//2.��ӡ�ָ���
		if (i < row - 1)//��ֹ���һ�д�ӡ
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("| ");
			}
			printf("\n");
		}
	}


}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int	y = 0;//��������
	printf("�����\n");

	while (1)//ֱ���������һ����ȷ������
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d", &x, &y);
		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)//���ǵ������Ϊ��ά�����Ǵ�1��ʼ��
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;//��������
	printf("������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж��Ƿ����
//����1��ʾ��������
//����0��ʾ����û��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//û��
			}
		}
	}
	return 1;//����
}

//�ж��Ƿ�Ӯ�����
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//��n��	
	for (i = 0; i < row; i++)
	{
		int j = 0;
		int count1 = 0;
		for (j = 0; j < col; j++)
		{
			if ((board[i][j]) == '*')
				count1++;
			if (count1 == 5)
				return board[i][j];
		}
	}
	//��n��	
	for (i = 0; i < col; i++)//��
	{
		int j = 0;
		int count2 = 0;
		for (j = 0; j < row; j++)//��
		{
			if ((board[j][i]) == '*')
				count2++;
			if (count2 == 5)
				return board[j][i];
		}
	}

	//б����
	int count3 = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((board[i][j]) == '*' && (i == j))
				count3++;
			if (count3 == 5)
				return board[i][j];
		}
	}


	//��n��	
	for (i = 0; i < row; i++)
	{
		int j = 0;
		int count4 = 0;
		for (j = 0; j < col; j++)
		{
			if ((board[i][j]) == '#')
				count4++;
			if (count4 == 5)
				return board[i][j];
		}
	}
	//��n��	
	for (i = 0; i < col; i++)//��
	{
		int j = 0;
		int count4 = 0;
		for (j = 0; j < row; j++)//��
		{
			if ((board[j][i]) == '#')
				count4++;
			if (count4 == 5)
				return board[j][i];
		}
	}

	//б����
	int count5 = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((board[i][j]) == '#' && (i == j))
				count5++;
			if (count5 == 5)
				return board[i][j];
		}
	}



	//�ж��Ƿ����
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';//ƽ��Q
	}
	else
	{
		return 'C';//����C
	}
}
//���*����#ƽ��Q����C
