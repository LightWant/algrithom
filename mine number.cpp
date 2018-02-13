#include<iostream>
#include<string.h>
using namespace std;
#define MAX 25

int n, m, num[MAX][MAX];
const int dis[5][2] = {0,0,1,0,-1,0,0,1,0,-1};
char Map[MAX][MAX];
//是否找到解
bool ispos;

bool isout(int x, int y)  { return (x < 0|| y < 0|| x >= n|| y >= m); }
//判断第一行周围是否有0
bool location(int x, int y)
{
    int i, xx, yy;
    for(int i = 0; i < 5; i++)
    {
        xx = x + dis[i][0];
        yy = y + dis[i][1];
        if(!isout(xx, yy) && num[xx][yy] <= 0 ) return 0;
    }
    return true;
}
bool judge_final()
{//搜到最后判断最后一行是否合法
    int i;
    for(i = 0; i < m; i++)
        if(num[n-1][i] != 0) return false;
    return true;
}
void change(int x, int y)
{//放一个雷后就把周围的数字减一
    int i, xx, yy;
    for(i = 0; i < 5; i++)
    {
        xx= x + dis[i][0];
        yy= y + dis[i][1];
        if( isout(xx, yy) ) continue;
            --num[xx][yy];
    }
}
void c_back(int x, int y)
{//回溯，把减了的加回来
    int i, xx, yy;
    for(i = 0; i < 5; i++)
    {
        xx = x + dis[i][0];
        yy = y + dis[i][1];
        if(isout(xx, yy)) continue;
        ++num[xx][yy];
    }
}
void print()
{
    int i, j;
    for(i = 0;i < n; i++)
    {
        for(j = 0;j < m; j++)
            cout << Map[i][j];
        cout << endl;
    }
}
void dfs(int x, int y)
{
    //已经找到解了
    if( ispos ) return;

    if( x == n )
    {
        if( judge_final() )
        {
            ispos=1;
            print();

        }
        return;
    }
    if( y == m ) { dfs(x+1,0); return; }
    //第一行枚举
    if( x == 0 )
    {
        if(location(x,y))
        {//如果没零，就设为‘*’
            Map[x][y]='*';
            change(x,y);
            dfs(x,y+1);
            c_back(x,y);
        }
        Map[x][y]='.';
        dfs(x,y+1);
    }
    else{
    //通过上一行的条件剪枝
        if(num[x-1][y]==0)
        {
            Map[x][y]='.';
            dfs(x,y+1);
        }
        else if(num[x-1][y]==1)
            if(location(x,y))
        {
            Map[x][y]='*';
            change(x,y);
            dfs(x,y+1);
            c_back(x,y);
        }

    }

}
int main()
{
    int i,j,test,t_num;
    char c;
    cin>>test;
    for(t_num=1;t_num<=test;t_num++)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            cin>>c;
            num[i][j]=c-'0';
        }
        cout<<"Case "<<t_num<<":"<<endl;
        ispos=0;
        dfs(0,0);
    }
    return 0;
}
