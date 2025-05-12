// 拓扑排序的实现
// 从 AOV 网中选择一个没有前驱（入度为 0）的顶点并输出
// 从网中删除该顶点和以他为起点的边
// 重复步骤直到网为空 / 网中不存在无前驱的顶点（存在回路）
// 如果图中存在回路，则拓扑排序不存在
// 每个 AOV 网都有一个或者多个拓扑排序序列

bool TopologicalSort(Graph){
    InitStack(S);
    for(int i = 0; i < G.vexnum; i++){
        if(indegree[i] == 0){
            Push(S, i);
        }
    }
    int count = 0;
    while(isEmpty(S) != 0){
        Pop(S, i);
        print[count] = i;
        count++;
        for(int p = G.vertices[i].firstarc; p; p = p->nextarc){
            v = p->adjvex;
            indegree--;
            if(indegree[v] == 0){
                Push[S, v];
            }
        }
    }
    if(count < G.vexnum){
        return false;
    }
    else{
        return true;
    }
}

// 采用邻接表法实现拓扑排序

// DFS算法实现逆拓扑排序