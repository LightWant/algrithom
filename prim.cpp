///针对邻接矩阵的Prim算法
#include<stdio.h>
#include<string.h>
const int INF=0x3f3f3f3f;
const int MAXN=105;
bool vis[MAXN];
int lowc[MAXN];
int Prim(int cost[][MAXN],int n)///点是1~n
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[1]=true;
    for(int i=2; i<=n; i++)lowc[i]=cost[1][i];
    for(int i=2; i<=n; i++)
    {
        int minc=INF;
        int p=-1;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        if(minc==INF)return -1;///原图不连通
        ans+=minc;
        vis[p]=true;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&lowc[j]>cost[p][j])
                lowc[j]=cost[p][j];
    }
    return ans;
}
int main()
{
    int n,m;///n条边，m个顶点
    int maps[105][105];
    while (~scanf("%d%d",&n,&m))
    {
        memset(maps,INF,sizeof(maps));
        for (int i=0;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            maps[u][v]=w;
            maps[v][u]=w;
        }
        int ans=Prim(maps,m);
        printf("%d\n",ans);
    }
}
/**
10 5
1 2 6
1 3 3
1 4 4
1 5 5
2 3 7
2 4 7
2 5 8
3 4 6
3 5 9
4 5 2
*/
