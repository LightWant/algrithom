#include <iostream>
using namespace std;
#define MAX 10000000
#define MAX_VERTEX_NUM 20
/*˳��ջ�Ķ���*/
#define Stack_Size 100
typedef struct sqStack
{
       int *elem;
       int top;
       int stackSize;//ջ���鳤��
}sqStack;


/*˳��ջ�ĳ�ʼ��*/
void initStack_Sq(sqStack &S)
{
       S.elem=new int[Stack_Size];
       S.top=-1;
       S.stackSize=Stack_Size;
}
/*��ջ*/
void push(sqStack &S,int x)
{
       if(S.top==Stack_Size-1)
              cout<<"Stack Overflow!";
       S.elem[++S.top]=x;
}

/*��ջ*/
int pop(sqStack &S)
{
       int x;
       if(S.top==-1)
              cout<<"Stack Empty!";
       x=S.elem[S.top--];
       return x;
}
typedef struct EdgeNode
{//�߱���Ķ���
	int adjvex;//����ڽӵ��ڶ�����е�λ��
	struct EdgeNode * nextedge;//ָ����һ���߱���
}EdgeNode;
typedef struct VexNode
{//�������Ķ���
	char vex;//��Ŷ�����Ϣ
	EdgeNode * firstedge;//ָ���һ���߱���
	int indegree;
}VexNode;
typedef struct
{//�����Ķ���
	VexNode vexs[MAX_VERTEX_NUM];
	int vexnum,edgenum;
}LGraph;
/*��������ͼ���ڽӱ�*/
void CreateDG_AL(LGraph &G,int n,int e)
{
	int i,j,k;
	G.vexnum=n;
	G.edgenum=e;
	for(i=0;i<n;i++)
	{
		cin>>G.vexs[i].vex;
		G.vexs[i].firstedge=NULL;//��ʼ��Ϊ��
	}
	for(k=0;k<e;k++)
	{
		EdgeNode *p;
		cin>>i>>j;
		p=new EdgeNode;
		p->adjvex=j;
		p->nextedge=G.vexs[i].firstedge;
		G.vexs[i].firstedge=p;//����ͷ�巨
	}
}
//��������
void TopoSort(LGraph &G)
{
	sqStack S;
	initStack_Sq(S);
	EdgeNode *p;
	int count=0;
	int i,j;
	for(i=0;i<G.vexnum;i++)
		G.vexs[i].indegree=0;//��ʼ��Ϊ0
	for(i=0;i<G.vexnum;i++)
	{//���������������
		p=G.vexs[i].firstedge;
		while(p)
		{
			G.vexs[p->adjvex].indegree++;
			p=p->nextedge;
		}
	}
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i].indegree==0)
			push(S,i);//����Ϊ0�Ķ�����ջ,�����ջ�������Ϊ0�Ķ����������е�λ��
	while(S.top!=-1)
	{
		j=pop(S);
		cout<<G.vexs[j].vex<<" ";//��ջ����Ԫ�س�ջ��������������Ϊ0�Ķ������
		count++;//��������1
		p=G.vexs[j].firstedge;//��pָ�����Ϊ0�Ķ���ĵ�һ���߱���
		while(p)
		{
			G.vexs[p->adjvex].indegree--;//�����Ϊ0�Ķ�����ڽӵ����ȼ�1
			if(G.vexs[p->adjvex].indegree==0)
				push(S,p->adjvex);//�ȼ�1��Ķ�����������Ϊ0��������ջ
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
