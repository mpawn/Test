#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_SEX 5
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
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
	PeoInfo data[MAX];//����1000���������
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
}Contact;


//��ʼ��ͨѶ¼
void InitContact(Contact* ps);
//����ͨѶ¼
void AddContact(Contact* ps);
//��ӡͨѶ¼
void ShowContact(const Contact* ps);