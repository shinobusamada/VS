#include <stdio.h>
int BinarySearch(int A[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left; // 插入位置
}
// 改进的插入排序：使用二分查找定位插入位置
void ModInsertSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int x = A[i];
        // 在 A[0..i-1] 中找到插入位置
        int pos = BinarySearch(A, 0, i - 1, x);
        // 将 A[pos..i-1] 后移一位
        for (int j = i - 1; j >= pos; j--) {
            A[j + 1] = A[j];
        }
        // 插入元素
        A[pos] = x;
    }
}
int main() {
    int arr[] = {27,99,0,8,13,64,86,16,7,10,88,25,90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("原始数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    ModInsertSort(arr, n);
    printf("排序后数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    getchar();
    return 0;
}