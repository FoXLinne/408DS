// 折半查找，又称二分查找
// 仅适用于有序的顺序表

// 使用指针 low 和 high 分别指向表头和表尾元素
// low = 0
// high = TableLen - 1
// 使用 mid 指针指向 (low+high) / 2 的元素位置
// 将 mid 与需要查找的元素进行比较
    // 当元素 < mid，则在左侧部分，high 指针位置指向 mid - 1，
    // 重复执行操作
    // 当元素 > mid，则在右侧部分，low 指针位置指向 mid + 1，
    // 重复执行操作
    // 直到 low = high = (low+high) / 2 = 元素，则查找成功。
    // 直到 low = high = (low+high) / 2 != 元素，则再进行一步后，low > high，说明查找失败。

typedef int ElemType;

typedef struct {
    ElemType *elem;
    int TableLen;
}SSTable;

// 折半查找的实现 （适用于升序排序的顺序表）
int Binary_Search(SSTable L, ElemType key) {
    int low = 0;
    int high = L.TableLen - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (L.elem[mid] == key) {
            return mid;
        }
        else if (L.elem[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

// 链表没有随机存取的特性，无法使用折半查找。

// 折半查找判定树的构造
    // 如果 low 和 high 之间有奇数个元素，则 mid 分隔后，左右两部分元素个数相等。
    // 如果 low 和 high 之间有偶数个元素，则 mid 分隔后，左半部分元素要比右半部分少一个
    // 右子树节点数 - 左子树节点数 = 0 / 1
    // 折半查找二叉树一定是平衡二叉树（左右子树深度相差不大于 1）
    // 只有最下面一层是不满的，元素为 n 时，二叉树的树高 h = (向上取整)(log^2(n+1))，不包含失败节点，包含则 +1
    // 判定树节点关键字 左 < 中 < 右，满足二叉排序树的定义
    // 失败节点的数量 = 成功节点的空链域数量 = n+1

// 时间复杂度为 O(log(n)) 或 O(log^2(n))