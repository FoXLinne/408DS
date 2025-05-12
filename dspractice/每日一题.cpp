// 2010统考真题
// 将 n 个整数存放在一维数组 R 中，设计一个在时间和空间方面都尽可能高效的算法，将 R 中保存的序列循环左移 p （0 < p < n）位。即将 R 中的数据由 (X0, X1, X2, ..., Xn-1) 变换为 (Xp, Xp+1, ..., Xn-1, X0, X1, ..., Xp-1)。
// 1) 给出算法的基本设计思想
// 2) 用 C 语言实现算法，并给出完整的程序代码
// 3) 说明算法的时间复杂度和空间复杂度

// 先 Reverse 前 p 个元素，再 Reverse 后 n - p 个元素，最后 Reverse 整个数组。

#include <cstdio>
#include <cstdlib>
#define MAXSIZE 100

typedef struct SqList {
    int data[MAXSIZE];
    int length;
}SqList;

void Reverse(SqList &L, int to, int from){
    while(to < from){
        int temp = L.data[to];
        L.data[to] = L.data[from];
        L.data[from] = temp;
        to++;
        from--;
    }
}

void Exchange(SqList &L, int p, int n){
    Reverse(L, 0, p-1);
    Reverse(L, p, n-1);
    Reverse(L, 0, n-1);
}

// 2025.5.7
// 试编写带头结点的单链表L中删除一个最小值节点的高效算法（最小值节点唯一）
// 第一步，找最小值
// 第二步，删掉最小值
// 使用 p 指针遍历，使用 q 指针标记遍历到的节点中的最小值。
// 具体表现为，将 p 当前位置的值与 q 的值进行比较，若 p 的值小于 q 的值，则将 q 指向 p。
// 直到 p 遍历完链表，q 指向的就是最小值节点。
// 使用 pre 指针来记录 q 的前一个节点，方便删除操作。

typedef struct LNode {
    int data;
    struct LNode *next;

}LNode, *LinkList;

LinkList DeleteMinNode(LinkList &L){
    if(L->next == NULL){
        return false; // 链表为空
    }
    L = (LNode *) malloc(sizeof(LNode));
    LNode *p = L->next; // p 指向第一个节点
    LNode *pre = L; // pre 指向 q 的前一个节点
    LNode *minpre = pre;
    LNode *q = p; // q 指向最小值节点
    while(p != NULL){
        if(p->data < q->data){
            q = p; // 更新最小节点 q 的指针
            minpre = pre; // 使用 minpre 记录下来前驱节点
        }
        p = p->next;
        pre = pre->next;
        // 向后移动指针
    }
    minpre->next = q->next; // 改变前驱节点的 next 指针指向
    free(p);
    return L;
}

// 2025.5.7 (2)
// 使用头插法建立单链表
// 输入的次序和生成链表节点的次序是相反的
LinkList insert_link_list(LinkList &L,int x) {
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", x);
    while (x != -1){
        LNode *p = (LNode *) malloc(sizeof(LNode));
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

// 2025.5.10 (1)
// 使用尾插法建立单链表
// 输入的次序和生成链表节点的次序是相同的
// 操作表尾，设置尾指针 r，使 r 始终指向表尾

LinkList InsertLinkList_tail(LinkList &L, int x) {
    L = (LinkList) malloc(sizeof(LNode)); // 创建头节点
    LNode *s;
    LNode *r = L;
    scanf("%d", &x);
    while (x != -1) {   // 输入 -1 后不再创建节点，程序结束
        s = (LNode*) malloc(sizeof(LNode)); // 创建 s 节点
        s->data = x;
        r->next = s;
        r = s;
    }
    r->next = NULL; // 链表创建结束后，最后一个节点的 next 指向 NULL
    return L;
}

// 2025.5.10 (2)
// 给定一个带头结点的单链表 L，将其就地逆置（空间复杂度为O(1)）
// 方法 1 使用头插法，将从头节点后开始的第一个节点到最后一个节点依次接入头节点后，完成逆置
// 使用指针 p 指向开始操作的节点，指针 rear 为其后继节点
LinkList ReverseLinkList(LinkList &L) {
    LNode *p = L->next;
    LNode *rear;
    L->next = NULL;
    while (p != NULL) {
        rear = p->next;
        p->next = L->next;
        L->next = p;
        p = rear;
    }
    return L;
}

// 方法 2 直接反转 next 指针的方向（三指针法）
// 使用指针 p 指向开始操作的节点，pre 为其前驱节点，rear 为其后继节点
LinkList ReverseLinkList_tri(LinkList &L) {
    LNode *pre = L->next;
    LNode *p = pre->next;
    LNode *rear = p->next;
    pre->next = NULL;
    while (p != NULL) {
        p->next = pre;
        pre = p;
        p = rear;
        rear = rear->next;
    }
    L->next = p;
    return L;
}

// 2025.5.12 (1)
// 设在一个带头结点的单链表中所有元素的结点的数据值无序，试编写一个函数删除表中所有介于给定的两个值（作为函数的参数给出）之间的元素的元素（若存在）。

// 思想
// 找 min < x < max
// 删除

void DeleteAB()