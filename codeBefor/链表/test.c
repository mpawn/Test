/*
����01 - ����������
ʵ��һ������ѡ��ʽ���������棬������������Ϊ��1 - 8�����ο��������£�
1.��ʾ������Ʒ����Ϣ
2.�޸�ĳ����Ʒ����Ϣ
3.����ĳ����Ʒ����Ϣ
4.ɾ��ĳ����Ʒ����Ϣ
5.����ĳ����Ʒ����Ϣ
6.��Ʒ���̲��˳�ϵͳ
7.����Ʒ�۸��������
8.(����)ɾ����������
����.�����̲��˳�ϵͳ
��������1 - 8ʱ��ִ����ع��ܣ���ɺ��ٴ���ʾ�˵����û�ѡ�񡣵�����������ֵʱ�����򲻴��̲��˳�ϵͳ��

��С��ֻ��ʵ�� main �������ɣ���ؽṹ�������������£�

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

�ò��������Ѱ����� ��lab52.h���С�
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab52.h" // �벻Ҫɾ������ͷ�ļ��������鲻ͨ��
int main()
{
	printf(
		"1.��ʾ������Ʒ����Ϣ\n"
		"2.�޸�ĳ����Ʒ����Ϣ\n"
		"3.����ĳ����Ʒ����Ϣ\n"
		"4.ɾ��ĳ����Ʒ����Ϣ\n"
		"5.����ĳ����Ʒ����Ϣ\n"
		"6.��Ʒ���̲��˳�ϵͳ\n"
		"7.����Ʒ�۸��������\n"
		"8.(����)ɾ����������\n"
		"����.�����̲��˳�ϵͳ\n");
	int input = 0;
	scanf("%d",&input);

	GoodsList L = ;

	switch (input)
	{
	case 1:output_all_items(GoodsList * L);
		break;
	case 2: ���1;
		break;
	case 3:���1;
		break;
	case 4: ���1;
		break;
	case 5:���1;
		break;
	case 6: ���1;
		break;
	case 7: ���1;
		break;
	case 8: ���1;
		break;
	default:���3;
		break;
	}


}








