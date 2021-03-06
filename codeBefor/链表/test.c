/*
链表：01 - 软件界面控制
实现一个数字选项式的启动界面，程序输入数据为（1 - 8），参考界面如下：
1.显示所有商品的信息
2.修改某个商品的信息
3.插入某个商品的信息
4.删除某个商品的信息
5.查找某个商品的信息
6.商品存盘并退出系统
7.对商品价格进行排序
8.(慎用)删除所有内容
其他.不存盘并退出系统
程序当输入1 - 8时，执行相关功能，完成后再次显示菜单让用户选择。当输入其它数值时，程序不存盘并退出系统。

本小题只需实现 main 函数即可，相关结构及函数声明如下：

#define GOODS_FILE_NAME "goodsinfo.txt"

#define MAX_ID_LEN 30

#define MAX_NAME_LEN 30

#define MAX_PRICE_LEN 30

#define MAX_DISCOUNT_LEN 30

typedef struct {
	char goods_id[MAX_ID_LEN];
	char goods_name[MAX_NAME_LEN];
	int goods_price;
	char goods_discount[MAX_DISCOUNT_LEN];
	int goods_amount;
	int goods_remain;
} GoodsInfo;

typedef struct node
{
	GoodsInfo data;
	struct node* next;
} GoodsList;

GoodsInfo read_goods_info();
void init_list(GoodsList** pL);
void destory_list(GoodsList** pL);
void destory_list_and_file(GoodsList** pL);
int save_to_file(GoodsList* L);
void output_one_item(GoodsList* L);
void output_all_items(GoodsList* L);
bool insert_item(GoodsList* L, GoodsInfo item, int choice);
bool delete_item(GoodsList* L, char* goods_id);
GoodsList* search_item(GoodsList* L, char* goods_id);
bool change_item(GoodsList* L, char* goods_id, GoodsInfo new_info);
void bubble_sort(GoodsList* L);
int read_line(char str[], int n);

该部分声明已包含在 “lab52.h”中。
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab52.h" // 请不要删除本行头文件，否则检查不通过
int main()
{
	printf(
		"1.显示所有商品的信息\n"
		"2.修改某个商品的信息\n"
		"3.插入某个商品的信息\n"
		"4.删除某个商品的信息\n"
		"5.查找某个商品的信息\n"
		"6.商品存盘并退出系统\n"
		"7.对商品价格进行排序\n"
		"8.(慎用)删除所有内容\n"
		"其他.不存盘并退出系统\n");
	int input = 0;
	scanf("%d",&input);

	GoodsList L = ;

	switch (input)
	{
	case 1:output_all_items(GoodsList * L);
		break;
	case 2: 语句1;
		break;
	case 3:语句1;
		break;
	case 4: 语句1;
		break;
	case 5:语句1;
		break;
	case 6: 语句1;
		break;
	case 7: 语句1;
		break;
	case 8: 语句1;
		break;
	default:语句3;
		break;
	}


}








