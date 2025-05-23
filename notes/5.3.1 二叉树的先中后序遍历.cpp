typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//1. 若二叉树为空，则什么都不做
//2. 若二叉树非空
    //1. 访问根结点
    //2. 先序遍历左子树
    //3. 先序遍历右子树
//先序遍历，在第一次路过该结点时访问结点
//每个节点都会被路过三次

void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
//1. 若二叉树为空，则什么都不做
//2. 若二叉树非空
    //1. 先序遍历左子树
    //2. 访问根结点
    //3. 先序遍历右子树
//中序遍历，在第二次路过该结点时访问结点
//每个节点都会被路过三次

void PostOder(BiTree T){
    if(T != NULL){
        PostOder(T->lchild);
        PostOder(T->rchild);
        visit(T);
    }
}
//1. 若二叉树为空，则什么都不做
//2. 若二叉树非空
    //1. 先序遍历左子树
    //2. 先序遍历右子树
    //3. 访问根结点
//后序遍历，在第三次路过该结点时访问结点
//每个节点都会被路过三次

int treeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        return l > r ? l + 1 : r + 1;
    }
}
//求树的深度
