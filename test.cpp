#include <bits/stdc++.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data);

/*关键函数*/
void reverseList(Node* head) {
    Node* p = head->next;
    Node* q;

    head->next = NULL;

    while (q != NULL) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);
    Node* L = newNode(-1);
    Node* last = L;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        last -> next = newNode(data);
        last = last -> next;
    }
    reverseList(L);
    Node* temp = L -> next;
    printf("%d", temp -> data);
    temp = temp -> next;
    while (temp != NULL) {
        printf(" %d", temp -> data);
        temp = temp -> next;
    }
    return 0;
}