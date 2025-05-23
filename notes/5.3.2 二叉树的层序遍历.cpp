//层序遍历算法思想
    //1. 初始化一个辅助队列
    //2. 根结点入队
    //3. 若队列非空，则队头结点出队
    //4. 访问该结点并将其左右孩子插入队尾

void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while(!isEmpty(Q)){
        DeQueue(Q, p);
        visit(p);
        if(p -> lchild != NULL){
            EnQueue(Q, p -> lchild);
        }
        if(p -> rchild != NULL){
            EnQueue(Q, p -> rchild);
        }
    }
}
//层序遍历