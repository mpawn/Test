/*
��˳���L��ɾ������ֵ����x��y֮��(����x��y)������Ԫ�أ�����y>=x����Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/
#define ElemType int
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>
//#include "list.h" // �벻Ҫɾ���������鲻ͨ��

//˳��ṹ
struct _seqlist {
    ElemType elem[MAXSIZE];//����
    int last;/*��¼���Ա������һ��Ԫ��������elem[ ]�е�λ�ã��±�ֵ)���ձ���Ϊ-1*/
};
typedef struct _seqlist SeqList;

void del_x2y(SeqList* L, ElemType x, ElemType y) {
    if (L->last == -1)
        return;
    int i = 0;
    int(*tmp)[MAXSIZE] = &(L->elem);
    for (i = 0; i <= L->last; i++)
    {
        if (*tmp >= x && *tmp <= y)
        {
            
        }
    }
}