// 4.1.1 串是由0个或多个字符组成的有限序列

// 4.1.2 串操作的实现
StrAssign(&T, chars) // 赋值操作，把串 T 赋值为 chars
StrCopy(&T, S) // 复制操作， 由串 S 复制得到串 T
StrEmpty(S) // 判空操作，判断串 S 是否为空，若为空返回 true，否则返回 false
StrCompare(S, T) // 比较操作，若串 S 和 T 相等，返回 0；若 S < T，返回 <0；若 S > T，返回 >0
StrLength(S) // 求串的长度，返回串 S 的元素个数
SubString(S, &Sub, pos, len) // 求子串，用 Sub 返回串 S 的第 pos 个字符起的 len 个字符的子串
Concat(&T, S1, S2) // 串的连接，用 T 返回由 S1 和 S2 连接而成的新串
Index(S, T) // 定位操作，若主串 S 中存在与子串 T 相同的子串，则返回它在主串 S 中第一次出现的位置，否则返回 0
Clear(&S) // 清空串，将串 S 清为空串
DestroyString(&S) // 销毁串，将串 S 销毁，释放内存

// 定义串
// 1. 定长顺序存储表示
#define MAXLEN 255 // 串的最大长度
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;

// 2. 堆分配存储表示
typedef struct{
    char *ch; // ch指向串的基地址
    int length;
}HString;

HString = S;
S.ch = (char *)malloc(sizeof(char) * MAXLEN); // 动态分配存储空间
S.length = 0; // 初始化串的长度为 0
// 用完后需要手动使用 free(S.ch) 释放内存

// 3. 块链存储表示
typedef struct StringNode{
    char ch; //每个节点存储一个字符
    struct StringNode *next;    
}StringNode, * String;

//如何让节点存储多个字符
typedef struct StringNode{
    char ch[4]; //每个节点存储一个字符
    struct StringNode *next;
}StringNode, * String;

// 求子串
SubString(S, &Sub, pos, len)
bool SubString(SString S, SString &Sub, int pos, int len){
    if (pos + len - 1 > S.length)
    return false;
    for (int i = pos, i < pos + len, i++)
        Sub.ch[i - pos +1] = S.ch[i];
    Sub.length = len;
    return true;
}

// 比较操作
StrCompare(S, T)
int StrCompare(SString S, SString T){
    for (int i = 1, i <= S.length && i <= T.length, i++){
        if (S.ch[i] != T.ch[i]){
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

// 定位操作，使用求子串与比较法结合进行定位

Index(S, T)
int Index(SString S, SString T){
    SString Sub;
    int i;
    int n = S.String;
    int m = T.String;
    while (i <= n - m + 1){
        SubString(S, Sub, i, m)
        if (StrCompare(Sub, T) != 0){
            i++;
        }
        return i;
    }
    return 0;
}

// 不利用基本操作函数的朴素模式匹配算法
// 对于主串 S 定义一个指针变量 i
// 对于模式串 T 定义一个指针变量 j
// 初始化指针 i, j = 1
// 在模式串长度内遍历 S 和 T 两个串，遇到匹配则 i++, j++
// 若遇到匹配失败，则 i 指向下一个子串的位置，j 回到模式串的第一个位置
// i = i-j+2; j = 1
// 完全匹配模式串后，统一令 i++, j++
// 此时 j > T.length (超出了模式串长度)，则说明匹配成功
// 返回串 S 中第一个字符的位置 i - T.length
// 时间复杂度 O(mn)

int Index(SString S, SString T){
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length){
        if (S.ch[i] != T.ch[j]){
            i = i-j+2;
            j = 1;
        }
        else (
            ++i;
            ++j;
        )
    }
    if (j > T.length){
        return i - T.length;
    }
    else{
        return 0;
    }
}

// KMP算法进行模式匹配
// 利用 next 数组进行匹配 主串指针不回溯
// 时间复杂度 O(m+n)

int Index_KMP(SString S, SString T, int next[]){
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length){
        if (j != 0 || S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        }
        else{
            j = next[j];
        }
    }
    if (j > T.length){
        return i - T.length;
    }
    else{
        return 0;
    }
}