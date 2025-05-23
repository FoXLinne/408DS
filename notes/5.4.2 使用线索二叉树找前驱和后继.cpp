//在中序线索二叉树中找到指定结点p的中序后继next
    //1. 如果p->rtag == 1，该右孩子指针已被线索化，next = p->rchild;
    //2. 如果p->rtag == 0，该结点存在右孩子；
    //3. 根据中序遍历规则为 *左根右*，该结点右子树中第一个被遍历的结点即为next； 
    //4. next具体为p的右子树中最左下角的结点。

//相关代码实现
//1. 找到二叉树中，第一个被中序遍历的结点
ThreadNode *FirstNode(ThreadNode *p){
    while(p->ltag == 0){
        p = p->lchild;
    }
    return p;
}
//2. 调用FirstNode()实现在rtag == 0时找到p结点的后继next
ThreadNode *NextNode(ThreadNode *p){
    if(p->rtag == 0){
        return FirstNode(p->rchild);
    }
    else{
        return p->rchild;
    }
}
//3. 结合代码1与2，可使用非递归算法对中序线索二叉树进行遍历
void InOrderNew(ThreadNode *T){
    for(ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p)){
        visit(p);
    }
}//该代码时间复杂度为O(1);

// 在中序线索二叉树中找到指定结点p的中序前驱pre
// 1. 如果p->ltag == 1，该左孩子指针已被线索化，pre = p->lchild;
// 2. 如果p->ltag == 1，该结点存在左孩子；
// 3. 根据中序遍历规则为 *左根右*，该结点左子树中最后一个被遍历的结点即为pre；
// 4. pre具体为p的左子树中最右下角的结点。

// 相关代码实现
// 1. 找到二叉树中，第一个被中序遍历的结点
ThreadNode *LastNode(ThreadNode *p){
    while (p->rtag == 0){
        p = p->rchild;
    }
    return p;
}
// 2. 调用LastNode()实现在ltag == 0时找到p结点的前驱pre
ThreadNode *PreNode(ThreadNode *p){
    if (p->ltag == 0){
        return LastNode(p->lchild);
    }
    else{
        return p->lchild;
    }
}
// 3. 结合代码1与2，可使用非递归算法对中序线索二叉树进行逆向遍历
void InOrderRev(ThreadNode *T){
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p)){
        visit(p);
    }
}

// 在先序线索二叉树中找到指定结点p的先序后继next
// 1. 如果p->rtag == 1，该右孩子指针已被线索化，next = p->rchild;
// 2. 如果p->rtag == 0，该结点存在右孩子，不一定存在左孩子；
// 3. 首先假设该结点存在左孩子，根据先序遍历规则为 *根左右*，该结点的左孩子即为next；
// 4. 如果没有左孩子，则该结点的右孩子即为next；

// 相关代码实现
// 1. 找到二叉树中，第一个被先序遍历的结点
ThreadNode *FirstNode(ThreadNode *p)
{
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}
// 2. 实现在rtag == 0时找到p结点的后继next
ThreadNode *NextNode(ThreadNode *p)
{
    if (p->rtag == 0)
    {
        if(p->lchild != NULL){
            return p->lchild;
        }
        else{
            return p->rchild;
        }
    }
    else
    {
        return p->rchild;
    }
}
// 3. 结合代码1与2，可使用非递归算法对中序线索二叉树进行遍历
void InOrderNew(ThreadNode *T)
{
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
    {
        visit(p);
    }
}

//当p->ltag == 0时，无法使用先序二叉树找到先序前驱pre；
//由于先序遍历的规则为 *根左右*，左右子树中的结点只可能作为根结点的后继出现，无法作为前驱出现；

//将链表改为三叉链表
//1. 如果能找到p的父结点，且p为左孩子，此时p的父结点即为pre。
//2. p为右孩子，且其左兄弟为空时，此时p的父结点即为pre。
//3. p为右孩子，且其左兄弟也存在时，此时p结点的pre为其左兄弟子树中最后一个被先序遍历的结点；
//pre具体表现为，从根结点出发，先向右下遍历，右边没路则往左走，左边没路则往右走，直到最后一个结点。
//4. p为根结点，则不存在先序前驱。

// 在后序线索二叉树中找到指定结点p的后序前驱pre
    // 1. 如果p->ltag == 1，左右孩子指针已被线索化，pre = p->lchild;
    // 2. 如果p->ltag == 0，该结点存在左孩子，不一定存在右孩子；
    // 3. 首先假设该结点存在右孩子，根据后序遍历规则为 *左右根*，该结点的右孩子即为pre；
    // 4. 如果没有右孩子，则该结点的左孩子即为pre；

// 寻找后序后继next
// 仅探讨p->rtag == 0的情况
// p存在右孩子，根据后序遍历规则 *左右根* ,左右子树中的结点只可能作为根结点的前驱出现，无法作为后继出现；

// 将链表改为三叉链表
// 1. 如果能找到p的父结点，且p为右孩子，此时p的父结点即为next。
// 2. p为左孩子，且其右兄弟为空时，此时p的父结点即为next。
// 3. p为左孩子，且其右兄弟也存在时，此时p结点的next为其右兄弟子树中最后一个被先序遍历的结点；
// pre具体表现为，从根结点出发，先向左下遍历，左边没路则往右走，右边没路则往左走，直到最后一个结点。
// 4. p为根结点，则不存在先序后继。