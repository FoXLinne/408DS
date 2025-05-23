//构造一个普通二叉树
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//构造线索二叉树
typedef struct ThreadNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

//tag = 0时，表示指针指向已有的孩子结点；
//tag = 1时，表示指针充当“线索”；

//暴力法找到中序序列的前驱
    //定义辅助变量，p为所指定的结点
    //q为二次遍历所访问结点，pre为该访问结点的前驱
    //final用于记录最终访问的结果
    BiTNode *p;
    BiTNode *pre = NULL;
    BiTNode *final = NULL;
    //定义访问结点q的函数
    void visit(BiTNode *q){
        if(q == p){
            final = p;
        }
        else{
            pre = q;
        }

    //进行二次中序遍历
    void InOrder(BiTree T)
    {
        if (T != NULL)
        {
            InOrder(T->lchild);
            visit(T);
            InOrder(T->rchild);
        }
    }

//在进行遍历的过程中将二叉树线索化
    //定义一个线索二叉树
    typedef struct ThreadNode{
        ElemType data;
        struct ThreadNode *lchild; *rchild;
        int ltag, rtag;
    }ThreadNode, ThreadTree;

    //将中序遍历的函数名修改为线索化函数
    void InThread(ThreadTree T){
        if(T != NULL){
            InThread(T->lchild);
            visit(T);
            InThread(T->rchild);
        }
    }

    //初始化将pre指针设为NULL
    ThreadNode *pre = NULL;

    //修改visit函数，使其在访问过程中线索化结点
    void visit(ThreadNode *q){
        if(q->lchild == NULL){
            q->lchild = pre;
            q->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = q;
            pre->rtag = 1;
        }
        pre = q;
    }

    //中序线索化二叉树调用函数汇总
    void CreateInThread(ThreadTree T){
        pre = NULL;
        if(T != NULL){
            InThread(T);
            if(pre->rchild == NULL){
                pre->rtag =1;
            }
        }
    }
    
