/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//链表的数据域
struct student
{
    char name[20];
    int num;
};


//链表的样子
struct Node {
    struct student data;
    struct Node* next;
};

//菜单
void menu()
{
    printf("############1.ADD       2.DEV   ################\n");
    printf("############3.SEARCH    4.MODIFY################\n");
    printf("############5.SHOW      6.CLEAR ################\n");
    printf("############7.DESTROY   0.EXIT  ################\n");
}

enum Option
{
    EXIT,
    ADD,
    DEV,
    SEARCH,
    MODIFY,
    SHOW,
    CLEAR,
    DESTROY
};

//创建表头,即单链表的初始化，即返回头指针
struct Node* creatList()
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    //headNode 成为了结构体变量
    if (headNode == NULL)
    {
        //打印错误原因的一个方式
        printf("creatList::%s\n", strerror(errno));
        //Not enough space
    }
    else
    {
        headNode->next = NULL;
    }
    return headNode;
}

//创建节点
struct Node* creatNode(struct student data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("creatNode::%s\n", strerror(errno));
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

//打印节点,遍历节点
void printList(struct Node* headNode)
{
    struct Node* pMove = headNode->next;
    printf("name\tnum\n");
    //当pMove不是空指针
    while (pMove)
    {
        printf("%s\t%d\n", pMove->data.name, pMove->data.num);
        pMove = pMove->next;
    }
    printf("\n");
}


//表头法插入
void insertNodeByHead(struct Node* headNode, struct student data)
{
    //1.创建插入的结点
    struct Node* newNode = creatNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

//表尾法插入
void insertNodeByEnd(struct Node* headNode, struct student data)
{
    struct Node* newNode = creatNode(data);
    struct Node* pMove = headNode;
    while (pMove->next)
    {
        pMove = pMove->next;
    }
    pMove->next = newNode;
}

//得到指向第i个节点的指针
struct Node* SearchPos(struct Node* headNode, int i)//头指针
{
    //第一个节点为头结点
    //第二个节点为首元结点
    int j = 1;
    struct Node* pMove = headNode;
    while (1)
    {
        if (j == i)
        {
            return pMove;
        }
        else if (j < i)
        {
            pMove = pMove->next;
            j++;
            if (pMove == NULL)
            {
                return pMove;
            }
        }
        else
        {
            return NULL;
        }
    }
}


//第i个元素前插入
void insertNodeByAnywhere(struct Node* headNode, struct student data)
{
    int i = 0;
    printf("请输入你想在第几个元素前插入:>");
    scanf("%d", &i);
    struct Node* newNode = creatNode(data);
    //查找第i+1个节点之前的一个节点
    struct Node* posNode = SearchPos(headNode, i);
    if (posNode == NULL)
    {
        printf("insertNodeByAnywher::%s\n", strerror(errno));
    }
    else
    {
        newNode->next = posNode->next;
        posNode->next = newNode;
    }
}


//增加元素
void Add(struct student* info, struct Node* list)
{
    int input = 0;
    printf("请输入学生的姓名:>");
    setbuf(stdin, NULL);
    scanf("%s", &(info->name));
    printf("请输入学生的学号:>");
    setbuf(stdin, NULL);
    scanf("%d", &(info->num));
    printf("请输入插入方式:1.头插法  2.尾插法  3.第i个元素前插入:>");
    setbuf(stdin, NULL);
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        insertNodeByHead(list, *info);
        break;
    case 2:
        insertNodeByEnd(list, *info);
        break;
    case 3:
        insertNodeByAnywhere(list, *info);
        break;
    default:
        printf("输入错误\n");
        break;
    }
    return;
}

//链表的删除:指定位置的删除
void deleteNodeByAppoinNum(struct Node* headNode, int num)
{
    struct Node* posNode = headNode->next;
    struct Node* posNodeFront = headNode;
    if (posNode == NULL)
        printf("无法删除,链表为空\n");
    else
    {
        while (posNode->data.num != num)
        {
            posNodeFront = posNode;
            posNode = posNodeFront->next;
            if (posNode == NULL)
            {
                printf("没有找到相关信息,无法删除\n");
                return;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
    }
}

//判断链表是否为空
int ListEmpty(struct Node* list)
{
    //空表:链表中无元素，称为空链表（头指针和头结点仍然在)
    //若L为空表，则返回1，否则返回0
    if (list->next)//非空
        return 0;
    else
        return 1;
}


//销毁单链表
void DestroyList_L(struct Node* list)
{
    struct Node* p;
    while (list)
    {
        p = list;
        list = list->next;
        free(p);
    }
    return;
}

//清空链表:链表-->空表
void ClearList(struct Node* list)
{
    struct Node* p, * q;
    p = list->next;
    while (p)//没有到表尾
    {
        q = p->next;
        free(p);
        p = q;
    }
    //头指针设置为空
    list->next = NULL;
    return;
}

//求单链表的表长
int countList(struct Node* list)
{
    struct Node* p = list->next;//p指向第一个节点
    int count = 0;
    while (p != NULL)//遍历
    {
        p = p->next;
        count++;
    }
    return count;
}

//查找第i个元素
void Search(struct Node* headNode)//头指针
{
    int j = 1;
    int i = 0;
    printf("请输入你想查找第几个元素:>");
    scanf("%d", &i);
    struct Node* pMove = headNode->next;
    while (1)
    {
        if (j == i)
        {
            printf("姓名:%s 学号:%d\n", pMove->data.name, pMove->data.num);
            return;
        }
        else if (j < i)
        {
            pMove = pMove->next;
            j++;
            if (pMove == NULL)
            {
                printf("超出链表长度\n");
                return;
            }
        }
        else
        {
            printf("输入错误\n");
            return;
        }
    }
}


int main()
{
    struct Node* list = creatList();
    struct student info;
    int input = 0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            Add(&info, list);
            break;
        case DEV:
            printf("请输入要删除学生的学号:>");
            scanf("%d", &info.num);
            deleteNodeByAppoinNum(list, info.num);
            break;
        case SEARCH:
            Search(list);
            break;
        case MODIFY:
            break;
        case SHOW:
            printList(list);
            break;
        case CLEAR:
            ClearList(list);
            break;
        case DESTROY:
            DestroyList_L(list);
            break;
        case EXIT:
            printf("退出\n");
            break;
        default:
            printf("选择错误\n");
            break;

        }
    } while (input);


    return 0;
}
*/