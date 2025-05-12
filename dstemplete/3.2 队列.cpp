// 队列 //

// 队列的定义 //
#define MaxSize 10;
typedef struct{
    ElemType data[MaxSize];  // 队列元素
    int front, rear;         // 队头，队尾指针
} SqQueue;

// 初始化 //
void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0     // 队头，队尾指针都指向0
}

// 判空 //
bool QueueEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

// 简单调用 //
void testQueue() {
    SqQueue Q;
    InitQueue(Q); 
}

// 入队 //

... // 定义队列
bool EnQueue(SqQueue &Q, ElemType x) {
    if((Q.rear + 1) % MaxSize == Q.front) // 判满，取模运算使队列循环
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

// 判满条件 (1)
// 当队尾指针 + 1 = 队头指针时判满 
// 定义中判空条件为队尾指针 = 队头指针
// *需牺牲 1 个存储单元 

// 计算队列元素个数 //
x = (Q.rear - Q.front + MaxSize) % MaxSize; 

// 出队 //
// 从队头出
bool DeQueue(SqQueue &Q, ElemType &x) {
    if(Q.rear == Q.front) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 查询 //
// 只需要查询队头元素
bool GetHead(SqQueue Q, ElemType &x) {
    if (Q.front == Q.rear) {
        return false;
    }
    x = Q.data[Q.front];
    return true;
}

// 判满 / 空条件 (2)
#define MaxSize 10;
typedef struct{
    ElemType data[MaxSize];  // 队列元素
    int front, rear;         // 队头，队尾指针
    int size;                // 记录队列长度，初始化时，size = 0
    // 删除操作时，size - 1
    // 插入操作时，size + 1
    // 判满条件：size == MaxSize
    // 判空条件：size == 0
} SqQueue;

// 判满 / 空条件 (3)
#define MaxSize 10;
typedef struct{
    ElemType data[MaxSize];  // 队列元素
    int front, rear;         // 队头，队尾指针
    int tag;                 
    // 删除操作时，tag = 1
    // 插入操作时，tag = 0
    // 判满条件：front == rear && tag == 1
    // 判空条件：front == rear && tag == 0
    // 0 表示空，1 表示满               
} SqQueue;
