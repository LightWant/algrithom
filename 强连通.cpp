#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct Edge
{
    int v,next;
}edge[10005];
int edgeNum;
int head[105];
int visit[105];
int n;

int componentMap[105];
int componentNum;
int dfn[105];
int low[105];

int stack[105];///栈
int stackSize;///栈大小

int inDegree[105];
int outDegree[105];

int leafNum,rootNum;

void addEdge(int u,int v)
{
    edge[edgeNum].v=v;
    edge[edgeNum].next=head[u];
    head[u]=edgeNum++;
}

void dfs(int u,int step)
{
    dfn[u]=step;///初始化dfn
    low[u]=step;///low初始化为dfn
    visit[u]=1;///标记此点已经访问
    stack[++stackSize]=u;///将词典压入栈
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(visit[v]==0)
            dfs(v,step+1);
        if(visit[v]==1)///visit不为2,即没有删除
            low[u]=min(low[u],low[v]);///维护low值
    }
    if(dfn[u]==low[u])///判断是否根节点，即强连通分量的根
    {
        componentNum++;
        int k;
        do
        {
            k=stack[stackSize--];///提取出顶点k
            componentMap[k]=componentNum;///将顶点k映射到强连通分量
            visit[k]=2;///将该顶点标记为已删除
        }
        while(k!=u);///从栈中提取出比根节点以上的节点，包括根节点。
    }
}

void tarjan()
{
    componentNum=0;///初始化强连通分量数
    stackSize=0;///初始化栈
    memset(visit,0,sizeof(visit));///初始化visit。
    for(int u=1;u<=n;u++)
    {
        if(visit[u]==0)///找到一个没有访问过的顶点，进去搜索。
            dfs(u,1);
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        edgeNum=0;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            while(1)
            {
                int v;
                scanf("%d",&v);
                if(v==0)
                    break;
                addEdge(i,v);
            }
        }

        tarjan();

        memset(inDegree,0,sizeof(inDegree));
        memset(outDegree,0,sizeof(outDegree));

        for(int u=1;u<=n;u++)
        {
            for(int i=head[u];i!=-1;i=edge[i].next)
            {
                int v=edge[i].v;
                if(componentMap[u]!=componentMap[v])///必须是u，v处在不同的强连通分量里面才能算入度和出度
                {
                    outDegree[componentMap[u]]++;
                    inDegree[componentMap[v]]++;
                }
            }
        }

        leafNum=rootNum=0;///rootNum存储入度为0的顶点的数量，leafNum存储的是出度为0的顶点的数量
        for(int u=1;u<=componentNum;u++)
        {
            if(outDegree[u]==0)
                leafNum++;
            if(inDegree[u]==0)
                rootNum++;
        }

        printf("%d\n",rootNum);
        if(componentNum==1)///特判，如果缩点后的图只有一个顶点的话答案为0
            printf("0\n");
        else
            printf("%d\n",max(rootNum,leafNum));
    }
}
