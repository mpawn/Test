/*
从顺序表L中删除所有值介于x和y之间(包括x和y)的所有元素（假设y>=x），要求时间复杂度为O(n)，空间复杂度为O(1)。
*/
#define ElemType int
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>
//#include "list.h" // 请不要删除，否则检查不通过

//顺序结构
struct _seqlist {
    ElemType elem[MAXSIZE];//数组
    int last;/*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值)，空表置为-1*/
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