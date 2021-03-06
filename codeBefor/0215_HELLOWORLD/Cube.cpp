#include"Cube.h"
	void Cube::SetLength(int l)
	{
		m_L = l;
	}
	int Cube::GetLength()
	{
		return m_L;
	}
	void Cube::SetHigh(int h)
	{
		m_H = h;
	}
	int Cube::GetHigh()
	{
		return m_H;
	}
	void Cube::SetWidth(int w)
	{
		m_W = w;
	}
	int Cube::GetWidth()
	{
		return m_W;
	}
	int Cube::GetS()
	{
		return (m_L * m_W + m_L * m_H + m_W * m_H) * 2;
	}
	int Cube::GetV()
	{
		return m_L * m_W * m_H;
	}