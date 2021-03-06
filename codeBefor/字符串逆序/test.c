#include<stdio.h>
int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverse_string(char arr[])//char* arr也是一样的
{
	char tmp = arr[0];
	int len = my_strlen(arr);
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	if (my_strlen(arr + 1) >= 2)
	{
		reverse_string(arr + 1);
	}
	arr[len - 1] = tmp;
}

int main()
{
	int i = 0;
	char arr[] = "abcdf";
	reverse_string(arr);
	for (i = 0; i < my_strlen(arr); i++)
	{
		printf("%c", arr[i]);
	}
	return 0;
}
