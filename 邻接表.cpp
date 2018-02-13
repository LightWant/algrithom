vector<int> G[MAX_V];

边上有属性时：
struct edge{
    int to;
    int cost;
};
vector<edge> G[MAX_V];

int main()
{
    int V, E;

    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int s, t;//from s to t

        cin >> s >> t;

        G[s].push_back(t);
        如果无向图，还要
        G[t].push_back(s);
    }

    这里操作图。
}

struct vertex{
    vector<vertex*> edge;
    1.
    2.
    3.
    ……
};

vertex G[MAX_V];

int main()
{
    int v, E;

    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int s, t;

        cin >> s >> t;

        G[s].edge.push_back(&G[t]);
      //  G[t].edge.push_back(&G[s])
    }
}
