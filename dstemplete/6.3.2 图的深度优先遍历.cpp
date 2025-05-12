// 设置数组标记已访问过的顶点
bool visited[MAX_VERTEX_NUM];

void DFS(Graph G, int v){
    visit(v);
    visited[v] = true;
    for(int w = FirstNeighbor(G, v);  w >= 0; w = NextNeighbor(G, v, w)){
        if(visited[w] != true){
            DFS(G, w);
        }
    }
}
// 对非连通图，则无法遍历所有剩余结点
// 改进版
void DFSTraverse(Graph G){
    for(int v = 0; v < G.vexnum; i++){
        visited[v] = false;
    }
    for(int v = 0; v < G.vexnum; i++){
        if (visited[i] != true){
            DFS(G, i);
        }
    }
}

// 由于递归调用，空间复杂度最坏情况下 = O(|V|)
// 时间复杂度 使用邻接矩阵 = O(|V|^2)，访问 V 个顶点，每个顶点的邻接点都需要 V 量级的时间
// 使用邻接表法 = O(|V|+|E|)，访问 V 个顶点共需要 V 量级的时间进行访问，每个顶点的邻接点都需要 E 量级的时间