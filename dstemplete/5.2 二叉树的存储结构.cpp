//二叉树的顺序存储结构

#define MAXSIZE 100
struct TreeNode
{
    ElemType value;
    bool isEmpty;
};

TreeNode t[MAXSIZE];

//顺序存储结构初始化
for(int i = 0; i < MAXSIZE; i++){
    t[i].isEmpty = true;
}

//二叉树的链式存储结构
struct ElemType{
    int value;
}

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree root = NULL;
//定义一棵空树

root = (BiTree) malloc(sizeof(BiTNode));
root -> data = {1};
root -> lchild = NULL;
root -> rchild = NULL;
//插入根结点

BiTNode *p = (BiTNode *) malloc(sizeof(BitNode));
p -> data = {2};
p -> lchild = NULL;
p -> rchild = NULL;
root -> lchild = p;
//插入新结点

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
    struct BiTNode *parent;
}BiTNode, *BiTree;
//加入父结点指针，构造三叉链表


