#pragma once
#include<iostream>
using namespace std;
class Cube
{
public:
	void SetLength(int l);
	int GetLength();
	void SetHigh(int h);
	int GetHigh();
	void SetWidth(int w);
	int GetWidth();
	int GetS();
	int GetV();
private:
	int m_H;
	int m_L;
	int m_W;
};