/*
Ҫ��:����Բ,��Բ��������ܳ�

���ӣ�Բ
ADT Circle{
    ���ݶ���D={r,x,y|r,x,y����ʵ��}
    ���ݹ�ϵ��R={<r,x,y>|r�ǰ뾶,<x,y>��Բ������}
    ��������:
    Circle(&C,r,x,y)
        �������:����һ��Բ
    double Area(C)
        ��ʼ����:Բ�Ѵ���
        �������:�������
    double Circumference(C)
        ��ʼ����:Բ�Ѵ���
        �������:�����ܳ�
    ......
}
*/
#include<stdio.h>
#include<assert.h>
#define PI 3.141592

typedef struct Circle {
    double r;
    double x;
    double y;
}C;


void Circle(C* pc)
{
    pc->r = 1;
    pc->x = 0;
    pc->y = 0;
}

double Area(const C* pc)
{
    assert(pc!=NULL);
    double ret = 0;
    double r = pc->r;
    ret = PI * r * r;
    return ret;
}

double Circumference(C* pc)
{
    assert(pc != NULL);
    double ret = 0;
    double r = pc->r;
    ret = 2* PI * r;
    return ret;
}

int main()
{
    C c = {0};
    //�������:����һ��Բ
    Circle(&c);
    //�������:�������
    double area = Area(&c);
    //�������:�����ܳ�
    double cir = Circumference(&c);
    printf("Area = %f \nCircumference = %f \n",area,cir);
    return 0;
}








