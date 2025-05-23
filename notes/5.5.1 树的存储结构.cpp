//使用数组顺序存储各个结点
//1. 双亲表示法
    //每个结点中存放数据元素+结点指向双亲结点的指针
    #define MAX_TREE_SIZE = 100;
    typedef struct{
        ElemType data;
        int parent;
    }PTNode;

    typedef struct{
        PTNode nodes[MAX_TREE_SIZE];
        int n;
    }PTree;
    //可以用于存储森林；
    //找父结点方便，找孩子结点不方便；
    //适用于并查集；

//使用链式存储各个结点
//1. 孩子表示法
    struct CTNode{
        int child;
        struct CTNode *next;
    };
    typedef struct{
        ElemType data;
        struct CTNode *firstChild;
    }CTBox;
    typedef struct{
        CTBox nodes[MAX_TREE_SIZE];
        int n, r;
    }CTree;
    //可以用于存储森林；
    //找孩子结点方便，找父结点不方便；
    //适用于服务流程树；

//2. 孩子兄弟表示法
    typedef struct CSNode{
        ElemType data;
        struct CSNode *firstChild; *nextSibling;
    }CSNode, *CSTree;
    //可用于表示森林，森林中每棵树的根结点同级关系，
    //从左到右分别视为前一个结点的兄弟；
    //形态上与二叉树类似；