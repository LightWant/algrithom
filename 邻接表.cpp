vector<int> G[MAX_V];

����������ʱ��
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
        �������ͼ����Ҫ
        G[t].push_back(s);
    }

    �������ͼ��
}

struct vertex{
    vector<vertex*> edge;
    1.
    2.
    3.
    ����
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
