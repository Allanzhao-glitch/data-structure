#include <stdio.h>
 
// 函数声明
void bubble_sort(int arr[], int len);
 
int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);  // 计算数组长度
 
    bubble_sort(arr, len);  // 调用冒泡排序函数
 
    // 打印排序后的数组
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}
 
// 冒泡排序函数
void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            // 交换元素位置
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}