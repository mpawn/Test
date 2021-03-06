#define _CRT_SECURE_NO_WARNINGS

//动态增加版本：默认可以存放3个人的信息
//当发现当前通讯录满的时候，我们进行扩容，一次增加2个人的信息
//3 5 7 9...
//#define MAX 1000
#define DEFAULT_SZ 3//默认可以存放3个人的信息
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_SEX 5
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
//人物定义
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//通讯录定义
typedef struct Contact
{
	PeoInfo* data;//创建指针
	int size;//记录当前已经有点元素个数
	int capacity;//当前通讯录最多可以放几个元素
}Contact;

//菜单
void menu();
//初始化通讯录
void InitContact(Contact* ps);
//增加通讯录
void AddContact(Contact* ps);
//打印通讯录
void ShowContact(const Contact* ps);
//删除指定的联系人
void DelContact(Contact* ps);
//查找指定人的信息
void SearchContact(const Contact* ps);
//修改
void ModifyContact(Contact* ps);
//删除通讯录
void DestroyContact(Contact* ps);
//保存文件
void SaveContact(Contact* ps);
//加载文件中的信息到通讯录
void LoadContact(Contact* ps);

enum Option
{
	EXIT,
	ADD,
	DEV,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};



int main()
{
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	InitContact(&con);
	
	do 
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input) 
		{
			case ADD:
				AddContact(&con);
				break;
			case DEV:
				DelContact(&con);
				break;
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case SORT:
				break;
			case SAVE:
				SaveContact(&con);
				break;
			case EXIT:
				//销毁通讯录-释放动态开辟内存
				SaveContact(&con);
				DestroyContact(&con);
				printf("退出通讯录\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	} while (input);


	return 0;
}

void menu()
{
	printf("****************************************\n");
	printf("******** 1.add            2.dev    *****\n");
	printf("******** 3.search         4.modify *****\n");
	printf("******** 5.show           6.sort   *****\n");
	printf("******** 7.save           0.exit   *****\n");
	printf("****************************************\n");
}


void InitContact(Contact* ps)
{
	ps->data = (PeoInfo*)malloc(DEFAULT_SZ *sizeof(PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;//通讯录最初只有一个元素
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}
//声明增容
void CheckCapacity(Contact* ps);

void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//读取文件，存放到通讯录中
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
}
void CheckCapacity(Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		PeoInfo* ptr=realloc(ps->data, (ps->capacity + 2) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

void AddContact(Contact* ps)
{
	//检测当前通讯录的容量
	//1.如果满了，就增加空间
	//2.如果没满，啥也不干
	CheckCapacity(ps);
	//增加数据
	printf("请输入添加人的名字:>");
	scanf("%s", ps->data[ps->size].name);
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

void ShowContact(const Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
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


static int FindByName(const Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//找不到
}



void DelContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s",name);
	//1.查找要删除的人在什么位置
	//找到返回名字所在的元素的下标
	//找不到返回-1
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr
			);
	}
}



void ModifyContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入修改后人的名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入修改后人的年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入修改后人的性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入修改后人的电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入修改后人的地址:>");
		scanf("%s", ps->data[pos].addr);

		ps->size++;
		printf("修改完成\n");
	}

}


void DestroyContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat","wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n",strerror(errno));
		return;
	}
	//写文件进通讯录
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);

	}
	fclose(pfWrite);
	pfWrite = NULL;
}

