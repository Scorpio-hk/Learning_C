// 方法1：
#include <stdio.h>
void bubble_sort(int arr[])//这里的arr看似是数组，实际是指针变量,int arr[] 表示的依然是一个指针： int *arr 。
{
    int sz = sizeof(arr) / sizeof(arr[0]); // 这里计算的不是数组大小，是指针大小,4/4=1
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
    bubble_sort(arr); // 是否可以正常排序？
    int i = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}