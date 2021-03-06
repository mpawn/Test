#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//�������ͺ���
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//���������ͺ���
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//����ģ���ṩͨ�õĽ�������
template<typename T>//����һ��ģ�壬T��һ��ͨ����������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	
	//swapInt(a, b);

	//���ַ�ʽ������ģ��ʵ�ֽ���
	//1���Զ������Ƶ����������Լ��Ƶ�T��int����
	mySwap(a, b);

	//2����ʾָ�����ͣ��Ҹ��߱�����T��int����
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}

