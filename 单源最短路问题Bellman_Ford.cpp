struct edge{int from, to, cost;};

edge es[MAX_E];

int d[MAX_V];
int V, E;

从s到所有点的最短距离
void shortest_path(int s)
{
    for(int i = 0; i < V; i++)
        d[i] = INF;

    d[s] = 0;

    while(true)
    {
        bool update = false;

        for(int i = 0; i < E; i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update)
            break;
    }
}

用Bellman_Ford检查负圈
bool find_negative_loop()
{
    memset(d, 0, sizeof(d));

    for(int i = 0; i < V; i++)
        for(int j = 0; j < E; j++)
    {
        edge e = es[j];
        if(d[e.to] > d[e.from] + e.cost){
            d[e.to] = d[e.from] + e.cost;

            if(i == v - 1)
                return true;
        }
    }

    return false;
}
