//并查集的代码实现 —— 初始化
#define SIZE 100
int UFSets[SIZE];

void Initial(int S[]){
    for(int i=0; i<SIZE; i++){
        S[i] = -1;
    }
}

// 查找操作 (时间复杂度最坏情况下为O(n))
int Find(int S[], int x)
{
    while (S[x] < 0)
    {
        x = S[x];
    }
    return x;
}

//合并操作 (时间复杂度为O(1))
void Union(int S[], int root1, int root2){
    if(root1 == root2){
        return;
    }
    S[root2] = root1;
}

// 对合并操作进行优化
// 1. 将小树的根结点并入大树，成为大树根结点的子树
// 2. 将每棵树根结点的S[]数组赋值为该树中结点数量
// 3. 通过比较两棵树中根结点S[]绝对值的大小即可判断出如何合并为优

void Union_fixed(int S[], int root1, int root2){
    if(root1 == root2){
        return;
    }
    if(S[root1] > S[root2]){    // 同为负数，越大的其绝对值反而小，所以root1合并至root2
        S[root2] += S[root1];
        S[root1] = root2;
    }
    else{
        S[root1] += S[root2];
        S[root2] = root1;
    }
}

// 该方法构造的树，最高长度不超过log^2(n)(向下取整)+1
// Union算法优化后，Find函数的最坏时间复杂度降低为 log^2(n)