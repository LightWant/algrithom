#include <iostream>
using namespace std;
#define MAX 10000000
#define MAX_VERTEX_NUM 20
/*顺序栈的定义*/
#define Stack_Size 100
typedef struct sqStack
{
       int *elem;
       int top;
       int stackSize;//栈数组长度
}sqStack;


/*顺序栈的初始化*/
void initStack_Sq(sqStack &S)
{
       S.elem=new int[Stack_Size];
       S.top=-1;
       S.stackSize=Stack_Size;
}
/*入栈*/
void push(sqStack &S,int x)
{
       if(S.top==Stack_Size-1)
              cout<<"Stack Overflow!";
       S.elem[++S.top]=x;
}

/*出栈*/
int pop(sqStack &S)
{
       int x;
       if(S.top==-1)
              cout<<"Stack Empty!";
       x=S.elem[S.top--];
       return x;
}
typedef struct EdgeNode
{//边表结点的定义
	int adjvex;//存放邻接点在顶点表中的位置
	struct EdgeNode * nextedge;//指向下一个边表结点
}EdgeNode;
typedef struct VexNode
{//顶点表结点的定义
	char vex;//存放顶点信息
	EdgeNode * firstedge;//指向第一个边表结点
	int indegree;
}VexNode;
typedef struct
{//顶点表的定义
	VexNode vexs[MAX_VERTEX_NUM];
	int vexnum,edgenum;
}LGraph;
/*构造有向图的邻接表*/
void CreateDG_AL(LGraph &G,int n,int e)
{
	int i,j,k;
	G.vexnum=n;
	G.edgenum=e;
	for(i=0;i<n;i++)
	{
		cin>>G.vexs[i].vex;
		G.vexs[i].firstedge=NULL;//初始化为空
	}
	for(k=0;k<e;k++)
	{
		EdgeNode *p;
		cin>>i>>j;
		p=new EdgeNode;
		p->adjvex=j;
		p->nextedge=G.vexs[i].firstedge;
		G.vexs[i].firstedge=p;//采用头插法
	}
}
//拓扑排序
void TopoSort(LGraph &G)
{
	sqStack S;
	initStack_Sq(S);
	EdgeNode *p;
	int count=0;
	int i,j;
	for(i=0;i<G.vexnum;i++)
		G.vexs[i].indegree=0;//初始化为0
	for(i=0;i<G.vexnum;i++)
	{//计算各个顶点的入度
		p=G.vexs[i].firstedge;
		while(p)
		{
			G.vexs[p->adjvex].indegree++;
			p=p->nextedge;
		}
	}
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i].indegree==0)
			push(S,i);//将度为0的顶点入栈,这里进栈的是入度为0的顶点在数组中的位置
	while(S.top!=-1)
	{
		j=pop(S);
		cout<<G.vexs[j].vex<<" ";//将栈顶的元素出栈且输出，即将入度为0的顶点输出
		count++;//计数器加1
		p=G.vexs[j].firstedge;//让p指向入度为0的顶点的第一个边表结点
		while(p)
		{
			G.vexs[p->adjvex].indegree--;//将入度为0的顶点的邻接点的入度减1
			if(G.vexs[p->adjvex].indegree==0)
				push(S,p->adjvex);//度减1后的顶点如果其入度为0，则将其入栈
			p=p->nextedge;
		}
	}
	if(count<G.vexnum)
		cout<<"Network G has citcuits!"<<endl;
}
void main()
{
	freopen("in.txt","r",stdin);
	LGraph G;
	CreateDG_AL(G,6,9);
	TopoSort(G);
}
