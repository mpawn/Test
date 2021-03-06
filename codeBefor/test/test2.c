/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//�����������
struct student
{
    char name[20];
    int num;
};


//���������
struct Node {
    struct student data;
    struct Node* next;
};

//�˵�
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

//������ͷ,��������ĳ�ʼ����������ͷָ��
struct Node* creatList()
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    //headNode ��Ϊ�˽ṹ�����
    if (headNode == NULL)
    {
        //��ӡ����ԭ���һ����ʽ
        printf("creatList::%s\n", strerror(errno));
        //Not enough space
    }
    else
    {
        headNode->next = NULL;
    }
    return headNode;
}

//�����ڵ�
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

//��ӡ�ڵ�,�����ڵ�
void printList(struct Node* headNode)
{
    struct Node* pMove = headNode->next;
    printf("name\tnum\n");
    //��pMove���ǿ�ָ��
    while (pMove)
    {
        printf("%s\t%d\n", pMove->data.name, pMove->data.num);
        pMove = pMove->next;
    }
    printf("\n");
}


//��ͷ������
void insertNodeByHead(struct Node* headNode, struct student data)
{
    //1.��������Ľ��
    struct Node* newNode = creatNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

//��β������
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

//�õ�ָ���i���ڵ��ָ��
struct Node* SearchPos(struct Node* headNode, int i)//ͷָ��
{
    //��һ���ڵ�Ϊͷ���
    //�ڶ����ڵ�Ϊ��Ԫ���
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


//��i��Ԫ��ǰ����
void insertNodeByAnywhere(struct Node* headNode, struct student data)
{
    int i = 0;
    printf("�����������ڵڼ���Ԫ��ǰ����:>");
    scanf("%d", &i);
    struct Node* newNode = creatNode(data);
    //���ҵ�i+1���ڵ�֮ǰ��һ���ڵ�
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


//����Ԫ��
void Add(struct student* info, struct Node* list)
{
    int input = 0;
    printf("������ѧ��������:>");
    setbuf(stdin, NULL);
    scanf("%s", &(info->name));
    printf("������ѧ����ѧ��:>");
    setbuf(stdin, NULL);
    scanf("%d", &(info->num));
    printf("��������뷽ʽ:1.ͷ�巨  2.β�巨  3.��i��Ԫ��ǰ����:>");
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
        printf("�������\n");
        break;
    }
    return;
}

//�����ɾ��:ָ��λ�õ�ɾ��
void deleteNodeByAppoinNum(struct Node* headNode, int num)
{
    struct Node* posNode = headNode->next;
    struct Node* posNodeFront = headNode;
    if (posNode == NULL)
        printf("�޷�ɾ��,����Ϊ��\n");
    else
    {
        while (posNode->data.num != num)
        {
            posNodeFront = posNode;
            posNode = posNodeFront->next;
            if (posNode == NULL)
            {
                printf("û���ҵ������Ϣ,�޷�ɾ��\n");
                return;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
    }
}

//�ж������Ƿ�Ϊ��
int ListEmpty(struct Node* list)
{
    //�ձ�:��������Ԫ�أ���Ϊ������ͷָ���ͷ�����Ȼ��)
    //��LΪ�ձ��򷵻�1�����򷵻�0
    if (list->next)//�ǿ�
        return 0;
    else
        return 1;
}


//���ٵ�����
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

//�������:����-->�ձ�
void ClearList(struct Node* list)
{
    struct Node* p, * q;
    p = list->next;
    while (p)//û�е���β
    {
        q = p->next;
        free(p);
        p = q;
    }
    //ͷָ������Ϊ��
    list->next = NULL;
    return;
}

//������ı�
int countList(struct Node* list)
{
    struct Node* p = list->next;//pָ���һ���ڵ�
    int count = 0;
    while (p != NULL)//����
    {
        p = p->next;
        count++;
    }
    return count;
}

//���ҵ�i��Ԫ��
void Search(struct Node* headNode)//ͷָ��
{
    int j = 1;
    int i = 0;
    printf("������������ҵڼ���Ԫ��:>");
    scanf("%d", &i);
    struct Node* pMove = headNode->next;
    while (1)
    {
        if (j == i)
        {
            printf("����:%s ѧ��:%d\n", pMove->data.name, pMove->data.num);
            return;
        }
        else if (j < i)
        {
            pMove = pMove->next;
            j++;
            if (pMove == NULL)
            {
                printf("����������\n");
                return;
            }
        }
        else
        {
            printf("�������\n");
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
        printf("��ѡ��:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            Add(&info, list);
            break;
        case DEV:
            printf("������Ҫɾ��ѧ����ѧ��:>");
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
            printf("�˳�\n");
            break;
        default:
            printf("ѡ�����\n");
            break;

        }
    } while (input);


    return 0;
}
*/