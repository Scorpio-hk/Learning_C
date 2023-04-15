// 方法1：
#include <stdio.h>
void bubble_sort(int arr[],int sz)//int arr[] 表示的依然是一个指针： int *arr
//void bubble_sort(int *arr,int sz)  同样正确 
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int main()
{
    int arr[] = {3, 1, 7, 5, 8, 9, 0, 2, 4, 6};
    int sz = sizeof(arr) / sizeof(arr[0]); 
    bubble_sort(arr,sz); 
    int i = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}