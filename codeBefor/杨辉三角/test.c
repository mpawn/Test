/*
3.在屏幕上打印杨辉三角。
1
1 1
1 2 1
1 3 3 1
*/
#include<stdio.h>
#define ROW 20//行
#define COL 20+1//列多1，防止溢出


int main()
{
//建立数组储存杨辉三角
	int arr[ROW][COL] = { 0 };
	arr[0][1] = 1;
	int i = 0;
	int j = 0;
	for (i = 1; i <ROW; i++)
	{
		j = 1;
		for (j = 1; j <COL; j++)
		{
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
			if (arr[i][j] == 0)
			{
				break;
			}
		}
	}

//打印杨辉三角
	for (i = 0; i < ROW; i++)
	{
		j = 1;
		for (j = 1; j < COL; j++)
		{
			printf("%d ",arr[i][j]);
			if (arr[i][j+1] == 0)
			{
				printf("\n");
				break;
			}
		}
	}
	return 0;
}