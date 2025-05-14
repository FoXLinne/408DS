#include <stdio.h>   // 用于printf
#include <stdlib.h>  // 用于malloc, free, abs
#include <stdbool.h> // 用于bool类型（如果需要，但这里不是必须的）

// 链表节点结构定义
typedef struct LNode {
    int data;         // 节点数据，这里使用整数作为示例
    struct LNode* next; // 指向下一个节点的指针
} LNode, *LinkList;   // LNode 是结构体类型，LinkList 是 LNode* 的别名

// 辅助函数：创建新节点
LNode* createNode(int data) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for LNode");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 您提供的 GetLength 函数
int GetLength(LinkList L) {
    int len = 0;
    while (L != NULL) {
        len++;
        L = L->next;
    }
    return len;
}

// 辅助函数：打印链表（假设head是一个虚拟头节点）
void printList(LinkList head) {
    if (head == NULL) {
        printf("List: NULL (Length including dummy: %d)\n", GetLength(head));
        return;
    }
    printf("List: Dummy"); // 打印虚拟头节点
    LinkList current = head->next; // 从第一个实际数据节点开始
    while (current != NULL) {
        printf(" -> %d", current->data);
        current = current->next;
    }
    printf(" -> NULL (Length including dummy: %d)\n", GetLength(head));
}

// 您提供的 FindPublicNode2 函数
LNode* FindPublicNode2(LinkList L1, LinkList L2) {
    LNode* p = L1->next;
    LNode* q = L2->next;
    int L1length = GetLength(L1);
    int L2length = GetLength(L2);

    int offset = abs(L1length - L2length);

    if (L1length <= L2length) {
        for (int i = 0; i < offset; i++) {
            if (q == NULL) return NULL; // 增加一个安全检查，防止q在循环中提前变为NULL
            q = q->next;
        }
    }
    else { // L1length > L2length
        for (int i = 0; i < offset; i++) {
            if (p == NULL) return NULL; // 增加一个安全检查，防止p在循环中提前变为NULL
            p = p->next;
        }
    }

    while (p != NULL && q != NULL) {
        if (p == q) {
            return p;
        }
        p = p->next;
        q = q->next;
    }
    return NULL;
}

// 辅助函数：释放链表内存（从虚拟头节点开始释放）
void freeList(LinkList head) {
    LinkList current = head;
    while (current != NULL) {
        LinkList next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    LNode* dummy1, *dummy2;
    LNode* common_node; // 用于创建相交部分的节点
    LNode* result;

    printf("--- FindPublicNode2 函数测试样例 ---\n\n");

    // 场景1：两个链表相交
    printf("场景1：两个链表相交。\n");
    // 创建公共尾部：4 -> 5 -> NULL
    LNode* common_tail_1 = createNode(4);
    common_tail_1->next = createNode(5);

    // 链表1：Dummy -> 1 -> 2 -> 3 -> (公共部分)4 -> 5 -> NULL
    dummy1 = createNode(0); // 虚拟头节点
    dummy1->next = createNode(1);
    dummy1->next->next = createNode(2);
    dummy1->next->next->next = createNode(3);
    dummy1->next->next->next->next = common_tail_1;

    // 链表2：Dummy -> 10 -> 11 -> (公共部分)4 -> 5 -> NULL
    dummy2 = createNode(0); // 虚拟头节点
    dummy2->next = createNode(10);
    dummy2->next->next = createNode(11);
    dummy2->next->next->next = common_tail_1; // 连接到公共部分

    printList(dummy1);
    printList(dummy2);

    result = FindPublicNode2(dummy1, dummy2);
    if (result != NULL) {
        printf("预期结果：数据为 4 的节点。实际结果：数据为 %d 的节点\n", result->data);
    } else {
        printf("预期结果：数据为 4 的节点。实际结果：NULL (未找到公共节点)\n");
    }
    // 释放内存：分别释放非公共部分和虚拟头节点，最后释放公共部分
    LinkList current_free = dummy1;
    while(current_free != common_tail_1 && current_free != NULL) {
        LinkList next_free = current_free->next;
        free(current_free);
        current_free = next_free;
    }
    current_free = dummy2;
    while(current_free != common_tail_1 && current_free != NULL) {
        LinkList next_free = current_free->next;
        free(current_free);
        current_free = next_free;
    }
    freeList(common_tail_1); // 释放公共部分和其后的节点
    printf("\n");

    // 场景2：两个链表不相交
    printf("场景2：两个链表不相交。\n");
    dummy1 = createNode(0); // 虚拟头节点
    dummy1->next = createNode(1);
    dummy1->next->next = createNode(2);
    dummy1->next->next->next = createNode(3);

    dummy2 = createNode(0); // 虚拟头节点
    dummy2->next = createNode(10);
    dummy2->next->next = createNode(11);
    dummy2->next->next->next = createNode(12);

    printList(dummy1);
    printList(dummy2);

    result = FindPublicNode2(dummy1, dummy2);
    if (result == NULL) {
        printf("预期结果：NULL。实际结果：NULL\n");
    } else {
        printf("预期结果：NULL。实际结果：数据为 %d 的节点\n", result->data);
    }
    freeList(dummy1);
    freeList(dummy2);
    printf("\n");

    // 场景3：其中一个链表为空（只包含虚拟头节点）
    printf("场景3：其中一个链表为空。\n");
    dummy1 = createNode(0); // 虚拟头节点，next为NULL，表示空链表
    dummy2 = createNode(0); // 虚拟头节点
    dummy2->next = createNode(10);
    dummy2->next->next = createNode(11);

    printList(dummy1);
    printList(dummy2);

    result = FindPublicNode2(dummy1, dummy2);
    if (result == NULL) {
        printf("预期结果：NULL。实际结果：NULL\n");
    } else {
        printf("预期结果：NULL。实际结果：数据为 %d 的节点\n", result->data);
    }
    freeList(dummy1);
    freeList(dummy2);
    printf("\n");

    // 场景4：两个链表都为空（只包含虚拟头节点）
    printf("场景4：两个链表都为空。\n");
    dummy1 = createNode(0); // 虚拟头节点，next为NULL
    dummy2 = createNode(0); // 虚拟头节点，next为NULL

    printList(dummy1);
    printList(dummy2);

    result = FindPublicNode2(dummy1, dummy2);
    if (result == NULL) {
        printf("预期结果：NULL。实际结果：NULL\n");
    } else {
        printf("预期结果：NULL。实际结果：数据为 %d 的节点\n", result->data);
    }
    freeList(dummy1);
    freeList(dummy2);
    printf("\n");

    // 场景5：链表在第一个数据节点处相交
    printf("场景5：链表在第一个数据节点处相交。\n");
    // 公共部分：1 -> 2 -> NULL
    common_node = createNode(1);
    common_node->next = createNode(2);

    dummy1 = createNode(0); // 虚拟头节点
    dummy1->next = common_node; // 直接指向公共部分

    dummy2 = createNode(0); // 虚拟头节点
    dummy2->next = common_node; // 直接指向公共部分

    printList(dummy1);
    printList(dummy2);

    result = FindPublicNode2(dummy1, dummy2);
    if (result != NULL) {
        printf("预期结果：数据为 1 的节点。实际结果：数据为 %d 的节点\n", result->data);
    } else {
        printf("预期结果：数据为 1 的节点。实际结果：NULL\n");
    }
    // 释放内存：只需释放虚拟头节点，然后释放公共部分
    free(dummy1);
    free(dummy2);
    freeList(common_node); // 释放公共部分
    printf("\n");

    // 场景6：链表较长，相交点在较深的位置
    printf("场景6：较长链表，相交点在较深的位置。\n");
    // 公共尾部：6 -> 7 -> NULL
    LNode* common_tail_2 = createNode(6);
    common_tail_2->next = createNode(7);

    // 链表1：Dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> (公共部分)6 -> 7 -> NULL
    dummy1 = createNode(0); // 虚拟头节点
    dummy1->next = createNode(1);
    dummy1->next->next = createNode(2);
    dummy1->next->next->next = createNode(3);
    dummy1->next->next->next->next = createNode(4);
    dummy1->next->next->next->next->next = createNode(5);
    dummy1->next->next->next->next->next->next = common_tail_2;

    // 链表2：Dummy -> 10 -> 11 -> 12 -> (公共部分)6 -> 7 -> NULL
    dummy2 = createNode(0); // 虚拟头节点
    dummy2->next = createNode(10);
    dummy2->next->next = createNode(11);
    dummy2->next->next->next = createNode(12);
    dummy2->next->next->next->next = common_tail_2; // 连接到公共部分

    printList(dummy1);
    printList(dummy2);

    result = FindPublicNode2(dummy1, dummy2);
    if (result != NULL) {
        printf("预期结果：数据为 6 的节点。实际结果：数据为 %d 的节点\n", result->data);
    } else {
        printf("预期结果：数据为 6 的节点。实际结果：NULL\n");
    }
    // 释放内存：同场景1
    current_free = dummy1;
    while(current_free != common_tail_2 && current_free != NULL) {
        LinkList next_free = current_free->next;
        free(current_free);
        current_free = next_free;
    }
    current_free = dummy2;
    while(current_free != common_tail_2 && current_free != NULL) {
        LinkList next_free = current_free->next;
        free(current_free);
        current_free = next_free;
    }
    freeList(common_tail_2); // 释放公共部分和其后的节点
    printf("\n");

    return 0;
}