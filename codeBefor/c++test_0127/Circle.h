#pragma once//防止重复包含
#include<iostream>
#include"Point.h"
using namespace std;
//头文件只留声明

//圆类
class Circle
{
public:
	//设置半径
	void setR(int r);
	//获取半径
	int getR();
	//设置圆心
	void setCenter(Point center);
	//获取圆心
	Point getCenter();
private:
	int m_R;
	Point m_Center;
};
