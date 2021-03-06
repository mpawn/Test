#include<stdio.h>
int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = sz - 1;
    int tmp = 0;
    int i = 0;
    while (left < right)
    {
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
