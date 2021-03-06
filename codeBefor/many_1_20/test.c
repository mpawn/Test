#define _CRT_SECURE_NO_WARNINGS
#define MAX 10

#include <stdio.h>
typedef struct poldata //polynomial����ʽ
{
	int sub;//subscript�±�
	int coe;//coefficientϵ��
	int index;//indexָ��
}poldata;

typedef struct polynomial //polynomial����ʽ
{
	poldata data[MAX];
	int size;
}pol;

//��ʼ������ʽ
void InitList(pol* ps)
{
	int i = 0;
	int input = 0;

	do
	{
		poldata* tmp = &(ps->data[i]);
		tmp->sub = i;
		printf("������ϵ��:>");
		scanf("%d", &tmp->coe);
		printf("������ָ��:>");
		scanf("%d", &tmp->index);
		printf("1.����������һ��   0.exit  :>");
		scanf("%d", &input);

		i++;
	} while (input);
	ps->size = i;
	return;
}

void AddList(pol* ps1, pol* ps2,pol* ps3)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int coe = 0;

	//��������1
	for (i = 0; i < ps1->size; i++)
	{
		tmp = ps1->data[i].index;
		//��������2
		for (j = 0; j < ps2->size; j++)
		{
			//������ָ����ͬ
			if (tmp == ps2->data[i].index)
			{
				coe = ps1->data[i].coe + ps2->data[i].coe;
				if (coe != 0)
				{
					ps3->data[i].sub = i;
					ps3->data[i].coe=coe;
					ps3->data[i].index =tmp;
					ps3->size++;
					break;
				}
			}
		}
		//��������ָ����ͬ
		if (tmp != ps2->data[i].index)
		{
			ps3->data[i].sub = i;
			ps3->data[i].coe = ps1->data[i].coe;
			ps3->data[i].index = tmp;
			ps3->size++;
		}
	}
	//����������1��������2ʣ��Ԫ���ƶ���3
	for (j = 0; j <= ps2->size; j++)
	{
		tmp = ps2->data[j].index;
		//��������3
		for (i = 0; i < ps3->size; i++)
		{
			//�ŵ�ĩβ
			if(tmp!= ps3->data[i].index)
			ps3->size++;
			ps3->data[ps3->size].sub = ps3->size;
			ps3->data[ps3->size].coe = ps2->data[j].coe;
			ps3->data[ps3->size].index = tmp;
		}
	}
	return;
}

void print(pol* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%dx^%d", ps->data[i].coe, ps->data[i].index);
		if (i < ps->size-1)
		{
			printf("+");
		}
	}
}
int main()
{
	pol poly1 = { 0 };
	pol poly2 = { 0 };
	pol poly3 = { 0 };
	printf("��һ������ʽ\n");
	InitList(&poly1);
	printf("�ڶ�������ʽ\n");
	InitList(&poly2);

	AddList(&poly1, &poly2, &poly3);

	print(&poly3);


	return 0;
}