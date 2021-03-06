/*
要求:定义圆,求圆的面积和周长

例子：圆
ADT Circle{
    数据对象：D={r,x,y|r,x,y都是实数}
    数据关系：R={<r,x,y>|r是半径,<x,y>是圆心坐标}
    基本操作:
    Circle(&C,r,x,y)
        操作结果:构造一个圆
    double Area(C)
        初始条件:圆已存在
        操作结果:计算面积
    double Circumference(C)
        初始条件:圆已存在
        操作结果:计算周长
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
    //操作结果:构造一个圆
    Circle(&c);
    //操作结果:计算面积
    double area = Area(&c);
    //操作结果:计算周长
    double cir = Circumference(&c);
    printf("Area = %f \nCircumference = %f \n",area,cir);
    return 0;
}








