// 广度优先 BFS 要点
// 1. 找到与一个顶点相邻的所有顶点
// 2. 标记访问过的顶点
// 3. 需要一个辅助队列标记访问过的顶点

bool visited[MAX_VERTEX_NUM];

void BFS(Graph G, int v){
    visit(v);
    visited[v] = true;
    Enqueue(Q, v);
    while(isEmpty(Q) != true){
        DeQueue(Q, v);
        for(w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
            if(visited[w] != true){
                visit(w);
                visited[w] = true;
                Enqueue(Q, w);
            }
        }
    }
}
// 对非连通图，则无法遍历所有剩余结点
// 改进版
void BFSTraverse(Graph G){
    for(int i = 0; i < G.vexnum; i++){
        visited[i] = false;
    }
    for(int i = 0; i < G.vexnum; i++){
        if(visited[i] != true){
            BFS(G, i);
        }
    }
}
// 调用函数次数 = 连通分量（极大连通子图）的数量
// 空间复杂度 最坏 = O(|V|)
// 时间复杂度 使用邻接矩阵 = O(|V|^2)，访问 V 个顶点，每个顶点的邻接点都需要 V 量级的时间
// 使用邻接表法 = O(|V|+|E|)，访问 V 个顶点共需要 V 量级的时间进行访问，每个顶点的邻接点都需要 E 量级的时间