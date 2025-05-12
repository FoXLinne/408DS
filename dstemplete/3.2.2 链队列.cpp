// 链队列的实现
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front;   // 队列的头指针
    LinkNode *rear;    // 队列的尾指针
} LinkQueue;

// 初始化链队列 (带头结点)
void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL; // 初始化时队列为空
}

// 判断链队列是否为空
bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear; // 队列为空
}

// 初始化链队列 (不带头结点)
void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = NULL; // 初始化时队列为空
}

// 判断链队列是否为空
bool IsEmpty(LinkQueue Q) {
    return Q.front == NULL; // 队列为空
}

// 入队操作 (带头结点)
bool EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; // 将新节点添加到队列尾部
    Q.rear = s;       // 更新队列尾指针
    return true;
}

// 入队操作 (不带头结点)
bool EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if (Q.rear == NULL) { // 队列为空
        Q.front = Q.rear = s; // 新节点既是头也是尾
    } else {
        Q.rear->next = s; // 将新节点添加到队列尾部
        Q.rear = s;       // 更新队列尾指针
    }
    return true;
}

// 出队操作 (带头结点)
bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (IsEmpty(Q)) return false; // 队列为空，出队失败
    LinkNode *p = Q.front->next;  // 指向队头节点
    x = p->data;                  // 保存出队元素
    Q.front->next = p->next;      // 更新头指针
    if (Q.rear == p) {            // 如果出队的是最后一个元素
        Q.rear = Q.front;         // 更新尾指针，更新状态为空队列
    }
    free(p);                      // 释放出队节点
    return true;
}

// 出队操作 (不带头结点)
bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (IsEmpty(Q)) return false; // 队列为空，出队失败
    LinkNode *p = Q.front;        // 指向队头节点
    x = p->data;                  // 保存出队元素
    Q.front = p->next;            // 更新头指针
    if (Q.front == NULL) {        // 如果出队的是最后一个元素
        Q.rear = NULL;            // 更新尾指针，更新状态为空队列
    }
    free(p);                      // 释放出队节点
    return true;
}