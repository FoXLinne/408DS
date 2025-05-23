// 关键字 唯一标识数据元素的数据项

// 查找表的常见操作
// 1. 查找符合的数据元素 静态查找表（仅关注查找速度）
// 2. 插入、删除数据元素 动态查找表（除了速度，也要关注操作是否方便实现）

// 平均查找长度 ASL 所有查找过程中进行关键字的比较的平均数

// 顺序查找又叫线性查找，通常用于线性表

typedef int ElemType;

typedef struct {
    ElemType *elem;
    int TableLen;
}SSTable;

int Search_Seq(SSTable ST, ElemType key) {
    int i;
    for (i = 0; i < ST.TableLen && ST.elem[i] != key; i++) {}
    return i == ST.TableLen ? -1 : i;
}

// 哨兵实现法
int Search_Seq2(SSTable ST, ElemType key) {
    ST.elem[0] = key;
    int i;
    for (i = ST.TableLen; ST.elem[i] != key; i--) {}
    return i;
}
// 无需判断指针越界，查找失败时返回 0，即哨兵节点的下标。
// 查找成功时，ASL(成功) = O(n)
// 查找失败时，ASL(失败) = O(n)

// 用查找判定树分析 ASL
// n 个成功节点（圆），n+1 个失败节点（方）
// 1. 一个成功节点的查找长度 = 自身所在层数
// 2. 一个失败节点的查找长度 = 其父节点存在层数

// 优化 1，将元素进行有序排列，使用查找判定树进行分析 （针对查找失败进行优化）
// 优化 2，被查概率不相等，则尝试将概率大的元素放在靠前位置，减小 ASL （针对查找成功进行优化）