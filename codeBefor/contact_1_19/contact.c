#include "contact.h"

void InitContact(Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//通讯录最初只有一个元素
}


void AddContact(Contact* ps) 
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入添加人的名字:>");
		scanf("%s",ps->data[ps->size].name);
		printf("请输入添加人的年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入添加人的性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入添加人的电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入添加人的地址:>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
	}

}void ShowContact(const Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄", "性别" ,"电话", "住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr
			);
		}
	}


}