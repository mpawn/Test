#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 12
#define COL 12

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//声明
void test();
void menu();
void game();
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘
void PlayerMove(char board[ROW][COL], int row, int col);//玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);//电脑下棋
char IsWin(char board[ROW][COL], int row, int col);//判断是否赢或和棋
int IsFull(char board[ROW][COL], int row, int col);//判断是否和棋

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
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("五子棋\n");
			game();//游戏的主程序
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);
}





//游戏菜单
void menu()
{
	printf("######################################\n");
	printf("#####    欢迎来到五子棋游戏    #######\n");
	printf("#####    1.play      0.exit    #######\n");
	printf("######################################\n");
}

游戏的主程序：游戏的实现;
void game()
{
	//创建一个数组：存放走出的棋盘信息
	char board[ROW][COL] = { '0' };//全部空格
	//为了以后想玩M*N子棋，以后在定义中直接修改就可以实现
	char ret = 0;

	//初始化棋盘
	InitBoard(board, ROW, COL);	//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)//玩家电脑轮流下
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//打印棋盘让玩家看
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);//判断游戏的四种情况： * 玩家赢  #电脑赢   Q平局  C继续下
		if (ret != 'C')//如果平局或一方获胜，就弹出
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//打印棋盘让玩家看
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//将其中棋盘上的'0'全部清空为空格' '
		}
	}
}

//打印棋盘
//期望打印成这个样子：
//   |   |
//---|---|---
//   |   |
//---|---|---
//   |   |
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 1; i <= col; i++)
	{
		printf(" %d  ", i);
	}
	printf("\n");
	for (i = 0; i < row; i++)//将两行打印三组
	{
		//1.打印一行的数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");//换行
		//2.打印分割行
		if (i < row - 1)//防止最后一行打印
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

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int	y = 0;//横纵坐标
	printf("玩家走\n");

	while (1)//直到玩家输入一个正确的坐标
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)//考虑到玩家认为二维数组是从1开始的
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;//横纵坐标
	printf("电脑走\n");
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

//判断是否和棋
//返回1表示棋盘满了
//返回0表示棋盘没满
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
				return 0;//没满
			}
		}
	}
	return 1;//满了
}

//判断是否赢或和棋
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//横n行	
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
	//竖n列	
	for (i = 0; i < col; i++)//列
	{
		int j = 0;
		int count2 = 0;
		for (j = 0; j < row; j++)//行
		{
			if ((board[j][i]) == '*')
				count2++;
			if (count2 == 5)
				return board[j][i];
		}
	}

	//斜方向
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


	//横n行	
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
	//竖n列	
	for (i = 0; i < col; i++)//列
	{
		int j = 0;
		int count4 = 0;
		for (j = 0; j < row; j++)//行
		{
			if ((board[j][i]) == '#')
				count4++;
			if (count4 == 5)
				return board[j][i];
		}
	}

	//斜方向
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



	//判断是否和棋
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';//平局Q
	}
	else
	{
		return 'C';//继续C
	}
}
//玩家*电脑#平局Q继续C
