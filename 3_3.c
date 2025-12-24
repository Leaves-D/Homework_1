#include <stdio.h>

// 非递归选择排序（升序）
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;  // 记录当前未排序部分的最小值位置
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // 更新最小值位置
            }
        }
        // 交换最小值到已排序部分的末尾
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// 非递归冒泡排序（升序，带优化）
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;  // 优化标志：判断本轮是否发生交换
    for (i = 0; i < n - 1; i++) {
        swapped = 0;  // 初始化未交换
        // 每轮将最大元素"冒泡"到末尾，已排序部分无需再比较
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换相邻元素
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // 标记发生交换
            }
        }
        // 如果本轮未交换，说明数组已有序，提前退出
        if (swapped == 0) {
            break;
        }
    }
}

// 打印数组
void printArray(int arr[], int size, const char* msg) {
    printf("%s", msg);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 测试用例数组
    int arr_selection[] = {64, 25, 12, 22, 11, 33, 55, 7};
    int arr_bubble[] = {64, 25, 12, 22, 11, 33, 55, 7};  // 与选
择排序用相同数组
    int n = sizeof(arr_selection) / sizeof(arr_selection[0]);
   // 测试选择排序
    printArray(arr_selection, n, "选择排序 - 排序前：");
    selectionSort(arr_selection, n);
    printArray(arr_selection, n, "选择排序 - 排序后：");

    // 测试冒泡排序
    printf("\n");
    printArray(arr_bubble, n, "冒泡排序 - 排序前：");
    bubbleSort(arr_bubble, n);
    printArray(arr_bubble, n, "冒泡排序 - 排序后：");

    return 0;
}
