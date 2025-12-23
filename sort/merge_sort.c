#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size = 20000;
int count = 1;

// 负责将两个已排序的部分合并为一个排序的部分
void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // 左子数组大小
    int n2 = r - m;     // 右子数组大小

    // 创建临时数组
    int L[n1], R[n2];

    // 拷贝数据到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    // 合并临时数组回到 a[l..r]
    i = 0; // 左子数组索引
    j = 0; // 右子数组索引
    k = l; // 原始数组索引
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝左边剩余的元素
    while (i < n1) {
        a[k] = L[i];
        i++; k++;
    }

    // 拷贝右边剩余的元素
    while (j < n2) {
        a[k] = R[j];
        j++; k++;
    }
}

// 递归函数：不断拆分直到长度为 1
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        // 防止溢出的中点计算法
        int m = l + (r - l) / 2;

        mergeSort(a, l, m);      // 排序左半部分
        mergeSort(a, m + 1, r);  // 排序右半部分
        merge(a, l, m, r);       // 合并
        /*
        for(int i=0;i<size;i++)
        printf("%2d ",a[i]);
        printf("\n\nCount:%d\n\n",count);
        count++;
        */
    }
}

int main() {
    srand(time(NULL));
    int a[size];

    printf("排序前:\n");
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 100;
        printf("%2d ", a[i]);
    }
    printf("\n");

    mergeSort(a, 0, size - 1);

    printf("排序后:\n");
    for (int i = 0; i < size; i++)
        printf("%2d ", a[i]);
    printf("\n");

    return 0;
}