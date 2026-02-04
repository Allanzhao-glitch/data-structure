#include <stdio.h>
 
// 函数声明
void selection_sort(int arr[], int len);
 
int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);  // 计算数组长度
 
    selection_sort(arr, len);  // 调用冒泡排序函数
 
    // 打印排序后的数组
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}

void selection_sort(int arr[], int len)
{
    int min = 0;
    for(int i= 0;i<len-1;i++){
    min  = i;
    for(int j = i+ 1;j<len;j++)
    {
        if(arr[j]<arr[min]){
            min = j;
        }
    }
    if(min != i){
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

    }
}
}