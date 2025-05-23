
#include <bits/stdc++.h>
using namespace std;

// 二路归并
    // 将两个有序的线性表合并为一个有序的线性表
    // 对比p1，p2所指元素，将较小的元素放入新表中

// 四路归并
    // 将四个有序的线性表合并为一个有序的线性表
    // 先对比p1，p2中的元素，将较小的再与p3对比，再将较小的与p4对比，最后将最小的放入新表中

// 进行m路归并时，需要进行m-1次对比

// 归并排序
    // 将代排元素各自看作一个子序列，进行归并
    // 将相邻的子序列进行两两归并，直到最后只剩下一个子序列

// 对于一个线性表A，其中的某两个相邻的子序列
// 归并

int *B = (int*)malloc(n * sizeof(int));
// 辅助数组 B

// 子序列 1 为从 low 到 mid 的有序序列
// 子序列 2 为从 mid+1 到 high 的有序序列
// 对 1，2 进行归并

void merge(int A[], int low, int mid, int high) {
    int i, j, k;

    for (k = low; k <= high; k++) {
        B[k] = A[k];
    }

    while (i <= mid && j <= high) {
        if (B[i] <= B[j]) {
            A[k++] = B[i++];
        } else {
            A[k++] = B[j++];
        }
    }

    while (i <= mid) {
        A[k++] = B[i++];
    }

    while (j <= high) {
        A[k++] = B[j++];
    }
}

void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

// 归并排序的算法效率分析
    // 时间复杂度为 O(nlogn)
    // 空间复杂度为 O(n)
    // 适合大规模数据的排序
    // 归并排序是稳定的排序算法
    // 适合链表的排序