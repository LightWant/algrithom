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

int stack[105];///ջ
int stackSize;///ջ��С

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
    dfn[u]=step;///��ʼ��dfn
    low[u]=step;///low��ʼ��Ϊdfn
    visit[u]=1;///��Ǵ˵��Ѿ�����
    stack[++stackSize]=u;///���ʵ�ѹ��ջ
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(visit[v]==0)
            dfs(v,step+1);
        if(visit[v]==1)///visit��Ϊ2,��û��ɾ��
            low[u]=min(low[u],low[v]);///ά��lowֵ
    }
    if(dfn[u]==low[u])///�ж��Ƿ���ڵ㣬��ǿ��ͨ�����ĸ�
    {
        componentNum++;
        int k;
        do
        {
            k=stack[stackSize--];///��ȡ������k
            componentMap[k]=componentNum;///������kӳ�䵽ǿ��ͨ����
            visit[k]=2;///���ö�����Ϊ��ɾ��
        }
        while(k!=u);///��ջ����ȡ���ȸ��ڵ����ϵĽڵ㣬�������ڵ㡣
    }
}

void tarjan()
{
    componentNum=0;///��ʼ��ǿ��ͨ������
    stackSize=0;///��ʼ��ջ
    memset(visit,0,sizeof(visit));///��ʼ��visit��
    for(int u=1;u<=n;u++)
    {
        if(visit[u]==0)///�ҵ�һ��û�з��ʹ��Ķ��㣬��ȥ������
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
                if(componentMap[u]!=componentMap[v])///������u��v���ڲ�ͬ��ǿ��ͨ���������������Ⱥͳ���
                {
                    outDegree[componentMap[u]]++;
                    inDegree[componentMap[v]]++;
                }
            }
        }

        leafNum=rootNum=0;///rootNum�洢���Ϊ0�Ķ����������leafNum�洢���ǳ���Ϊ0�Ķ��������
        for(int u=1;u<=componentNum;u++)
        {
            if(outDegree[u]==0)
                leafNum++;
            if(inDegree[u]==0)
                rootNum++;
        }

        printf("%d\n",rootNum);
        if(componentNum==1)///���У����������ͼֻ��һ������Ļ���Ϊ0
            printf("0\n");
        else
            printf("%d\n",max(rootNum,leafNum));
    }
}
