/*
10-1：栈（Stack） 修改如下程序（10.2节的栈示例）使它存储字符而不是整数。 增加 main 函数，用来要求用户输入一串圆括号或花括号，然后指出它们之间的嵌套是否正确。

输出范例：

Enter parentheses and/or braces: ()({})({})
Parentheses/braces are nested properly

Enter parentheses and/or braces: ((}
Parentheses/braces are NOT nested properly
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#define MAX 100
typedef char datatype;

typedef struct {
    datatype data[MAX];
    int top;
}SeqStack;

SeqStack* initStack() {
    SeqStack* head = (SeqStack*)malloc(sizeof(SeqStack));
    head->top = 0;
    memset(head, 0, MAX * sizeof(datatype));
    return head;
}

int isEmpty(SeqStack* head) {
    return head->top == 0;
}

int isFull(SeqStack* head) {
    return head->top == MAX;
}

int Push(SeqStack* head, datatype e) {
    if (isFull(head)) return 0;
    head->data[head->top] = e;
    ++head->top;
    return 1;
}

int Pop(SeqStack* head, datatype* e) {
    if (isEmpty(head)) return 0;
    --head->top;
    *e = head->data[head->top];
    return 1;
}

int main(void) {
    char s[100], op, i;
    SeqStack* stck = initStack();
    printf("Enter parentheses and/or braces:  ");
    scanf("%s", s);
    for (i = 0; s[i]; ++i) {
        if(s[i] == '(') Push(stck, s[i]);
        if (s[i] == '[') Push(stck, s[i]);
        if (s[i] == '{') Push(stck, s[i]);
        if (s[i] == ')') {
            Pop(stck, &op);
            if (op != '(') {
                printf("Parentheses/braces are NOT nested properly\n没有找到与')'匹配的'('。\n");
                return 1;
            }
        }
        if (s[i] == ']') {
            Pop(stck, &op);
            if (op != '[') {
                printf("Parentheses/braces are NOT nested properly\n没有找到与']'匹配的'['。\n");
                return 1;
            }
        }
        if (s[i] == '}') {
            Pop(stck, &op);
            if (op != '{') {
                printf("Parentheses/braces are NOT nested properly\n没有找到与'}'匹配的'{'。\n");
                return 1;
            }
        }
    }
    printf("Parentheses/braces are nested properly\n");
    return 0;
}