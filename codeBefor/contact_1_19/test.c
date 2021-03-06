#define _CRT_SECURE_NO_WARNINGS

//��̬���Ӱ汾��Ĭ�Ͽ��Դ��3���˵���Ϣ
//�����ֵ�ǰͨѶ¼����ʱ�����ǽ������ݣ�һ������2���˵���Ϣ
//3 5 7 9...
//#define MAX 1000
#define DEFAULT_SZ 3//Ĭ�Ͽ��Դ��3���˵���Ϣ
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_SEX 5
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
//���ﶨ��
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼����
typedef struct Contact
{
	PeoInfo* data;//����ָ��
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼�����Էż���Ԫ��
}Contact;

//�˵�
void menu();
//��ʼ��ͨѶ¼
void InitContact(Contact* ps);
//����ͨѶ¼
void AddContact(Contact* ps);
//��ӡͨѶ¼
void ShowContact(const Contact* ps);
//ɾ��ָ������ϵ��
void DelContact(Contact* ps);
//����ָ���˵���Ϣ
void SearchContact(const Contact* ps);
//�޸�
void ModifyContact(Contact* ps);
//ɾ��ͨѶ¼
void DestroyContact(Contact* ps);
//�����ļ�
void SaveContact(Contact* ps);
//�����ļ��е���Ϣ��ͨѶ¼
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
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	
	do 
	{
		menu();
		printf("��ѡ��:>");
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
				//����ͨѶ¼-�ͷŶ�̬�����ڴ�
				SaveContact(&con);
				DestroyContact(&con);
				printf("�˳�ͨѶ¼\n");
				break;
			default:
				printf("ѡ�����\n");
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
	ps->size = 0;//ͨѶ¼���ֻ��һ��Ԫ��
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}
//��������
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
	//��ȡ�ļ�����ŵ�ͨѶ¼��
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
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

void AddContact(Contact* ps)
{
	//��⵱ǰͨѶ¼������
	//1.������ˣ������ӿռ�
	//2.���û����ɶҲ����
	CheckCapacity(ps);
	//��������
	printf("����������˵�����:>");
	scanf("%s", ps->data[ps->size].name);
	printf("����������˵�����:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("����������˵��Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("����������˵ĵ绰:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("����������˵ĵ�ַ:>");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("��ӳɹ�\n");
}

void ShowContact(const Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	return -1;//�Ҳ���
}



void DelContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:>");
	scanf("%s",name);
	//1.����Ҫɾ��������ʲôλ��
	//�ҵ������������ڵ�Ԫ�ص��±�
	//�Ҳ�������-1
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(const Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	printf("�������޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("�������޸ĺ��˵�����:>");
		scanf("%s", ps->data[pos].name);
		printf("�������޸ĺ��˵�����:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������޸ĺ��˵��Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("�������޸ĺ��˵ĵ绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������޸ĺ��˵ĵ�ַ:>");
		scanf("%s", ps->data[pos].addr);

		ps->size++;
		printf("�޸����\n");
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
	//д�ļ���ͨѶ¼
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);

	}
	fclose(pfWrite);
	pfWrite = NULL;
}

