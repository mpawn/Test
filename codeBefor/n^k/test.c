#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double Pow(int n, int k)
{
	//n^k=n*n^(k-1)
	if (k < 0)
		return (1.0 / (Pow(n, -k)));
	else if (k == 0)
		return 1;
	else
		return n * Pow(n, k - 1);
}

int main()
{
	int n = 0;
	int k = 0;
	printf("���������n^k�Ľ����������n��k��>\n");
	scanf("%d%d", &n, &k);
	double ret = Pow(n, k);
	printf("ret=%lf\n", ret);
	return 0;
}

