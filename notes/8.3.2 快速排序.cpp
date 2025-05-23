// 快速排序

// 1. 分区
    // 用 low 和 high 指针分别指向数组的两端
    // 选择第一个元素为基准元素（pivot）
    // high向前遍历，找到第一个小于基准元素的元素，将其放到low的位置
    // low向后遍历，找到第一个大于基准元素的元素，将其放到high的位置
    // 重复进行直到 low = high，将基准元素放到该位置

// 2. 递归
    // 对基准元素左侧的子数组进行快速排序
    // 对基准元素右侧的子数组进行快速排序
    // 直到 low >= high

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    // 选取第一个元素为基准元素

    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];

        while (low < high && arr[low] <= pivot) {
            low++;
        }
        arr[high] = arr[low];
    }

    arr[low] = pivot;

    return low;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// 快速排序的算法效率分析
    // 平均时间复杂度为 O(nlogn)
    // 最坏时间复杂度为 O(n^2)，当数组已经有序时
    // 空间复杂度为 O(logn)，递归调用栈的深度
    // 适合大规模数据的排序
    // 快速排序是稳定的排序算法