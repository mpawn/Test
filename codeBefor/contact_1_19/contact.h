#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_SEX 5
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
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
	PeoInfo data[MAX];//创建1000个人物格子
	int size;//记录当前已经有点元素个数
}Contact;


//初始化通讯录
void InitContact(Contact* ps);
//增加通讯录
void AddContact(Contact* ps);
//打印通讯录
void ShowContact(const Contact* ps);