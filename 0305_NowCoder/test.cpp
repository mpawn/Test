#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> A(10);
	int count = 0;
	A.reserve(20);
	for (int i = 2; i <= 20; i++)
		if (i % 3 == 0 && i % 5 == 0) A[count++] = i;
	for (int i = 0; i < count; i++)
		cout << A[i] << " ";//15
	cout << endl;
}