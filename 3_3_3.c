#include <stdio.h>

// 打印数组元素，方便观察排序前后变化
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 冒泡排序（非递归，带优化）
void bubbleSort(int arr[], int n) {
    int i, j;
    int temp;           // 用于交换元素的临时变量
    int swapped;        // 标记是否发生交换，优化排序效率

    // 外层循环：控制排序趟数（最多需要n-1趟）
    for (i = 0; i < n - 1; i++) {
        swapped = 0;    // 每趟开始前默认未发生交换

        // 内层循环：比较并交换相邻元素
        // 每趟排序后，最大的元素会"浮"到数组末尾，因此每趟可少>比较i次
        for (j = 0; j < n - 1 - i; j++) {
            // 若当前元素大于后一个元素，则交换
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // 标记发生了交换
            }
        }

        // 若某趟未发生交换，说明数组已完全有序，可提前退出
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    // 测试数组
    int arr[] = {38, 9, 29, 7, 2, 15, 28};
    int n = sizeof(arr) / sizeof(arr[0]);  // 计算数组长度

    printf("冒泡排序测试：\n");
    printf("排序前的数组：");
    printArray(arr, n);

    // 调用冒泡排序函数
    bubbleSort(arr, n);

    printf("排序后的数组：");
    printArray(arr, n);

    return 0;
}
