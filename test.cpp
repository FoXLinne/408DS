#include <stdio.h>
#include <stdlib.h>

// 定义单链表结点结构
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

// 初始化链表（带头结点），创建一个链表，初始数据通过数组传入
LinkList CreateList(int arr[], int n) {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* tail = L;
    for (int i = 0; i < n; ++i) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = arr[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return L;
}

// 打印链表
void PrintList(LinkList L) {
    LNode* p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 删除链表中所有数据值介于 min 和 max 之间的结点（不含 min 和 max）
void DeleteBetweenMinMax(LinkList &L, int min, int max) {
    LNode* pre = L;
    LNode* p = L->next;
    while (p != NULL) {
        if (min < p->data && p->data < max) {
            pre->next = p->next;
            free(p);
            p = pre->next;  // 继续检查新的 p
        } else {
            pre = p;
            p = p->next;
        }
    }
}

// 主函数测试
int main() {
    int data[] = {7, 3, 10, 5, 2, 8, 1};
    int n = sizeof(data) / sizeof(data[0]);

    LinkList L = CreateList(data, n);
    printf("原链表：");
    PrintList(L);

    int min = 3, max = 8;
    DeleteBetweenMinMax(L, min, max);

    printf("删除介于 %d 和 %d 之间的元素后的链表：", min, max);
    PrintList(L);

    return 0;
}

