// 邻接矩阵法
// 对于无向图，第i个结点的度 = 第i行或第i列的非0元素个数
// 对于有向图，第i个结点的出度 = 第i行的非0元素；入度 = 第i列的非0元素，度 = 入度 + 出度
// 时间复杂度 = O(|V|)

// 存储带权图 / 网
    // 在矩阵中写入两个结点之间的边的权值
    // 如果两个结点之间不存在边，则权值为 ∞
    // 代码实现
    #define MaxVertexNum 100
    #define INFINITY //int类型的最大值//
    typedef char VertexType;
    typedef int EdgeType;
    typedef struct{
        VertexType Vex[MaxVertexNum];
        EdgeType Edge[MaxVertexNum][MaxVertexNum];
        int vexnum, arcnum;
    }MGraph;

// 空间复杂度为O(n^2)
// 性质
    // 图G的邻接矩阵图为A，则A^n的元素A^n[i][j]等于从顶点[j]到[j]的长度为n的路径的数目

// 邻接表法
    // 图
    typedef struct{
        AdjList vertices;
        int vexnum, arcnum;
    }ALGraph;

    // 顶点部分
    typedef struct VNode{
        VertexType data;
        ArcNode *first;
    }VNode, AdjList[MaxVertexNum];

    // 弧部分
    typedef struct ArcNode{
        int adjvex;
        struct ArcNode *next;
        // InfoType info; (权值)
    }ArcNode;
    // 无向图，空间复杂度 O(|V|+2|E|)
    // 有向图，空间复杂度 O(|V|+|E|)
    