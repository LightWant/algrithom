/*
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long  LL;

const int N = 2, M = 2, P = 2, MOD = 1e9 + 7;
struct Matrix{LL m[N][N];};

Matrix A={1,1,1,0};
Matrix I={1,0,0,1};//单位矩阵

Matrix multi(Matrix a,Matrix b)
{
    Matrix ans;
    for(int i=0;i<N;i++)//i， j控制行列
        for(int j=0;j<M;j++)
        {
            ans.m[i][j]=0;
            for(int k=0; k<P; k++)//k是a的列遍历和b的行遍历
                ans.m[i][j] += a.m[i][k] * b.m[k][j] % MOD;
            ans.m[i][j]%=MOD;//不能忘
        }
    return ans;
}
Matrix power(Matrix a,int k)
{
    Matrix ans=I,p=a;
    while(k)
    {
        if(k&1)
        {
            ans=multi(ans,p);
        }
        k>>=1;
        p=multi(p,p);
    }
    return ans;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        Matrix ans=power(A,n-1);
        printf("%lld\n",ans.m[0][0]);
    }
    return 0;
}
*/
#include <stdio.h>
#define MOD (1e9+7)

typedef long long ll;
struct maxtrix//原来c++不用typedef
{
    ll m[10][10];
};

struct point
{
    int x;
    int y;
};

int N;//维数，小于等于10

maxtrix E;//单位矩阵

maxtrix mulit( maxtrix a, maxtrix b )
{
    maxtrix p;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
    {
        p.m[i][j] = 0;
        for(int k = 0; k < N; ++k)
            p.m[i][j] += a.m[i][k] * b.m[k][j];
    }

    return p;
}

maxtrix add_mi( maxtrix a, maxtrix b, int N, char type)
{
    maxtrix p;

    if(type == '+')
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
        {
            p.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    else
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
        {
            p.m[i][j] = a.m[i][j] - b.m[i][j];
        }

    return p;
}

maxtrix strassen(maxtrix a, maxtrix b, point m, point n)
{
    if( y - x >= 7 )
        return mulit( a, b );
    point p1 = {0, 0};
    point p2 = {m.x, (m.y + n.y)/2};
    point p3 = {(m.x + n.x)/2,  (m.y + n.y)/2};
    point p4 = {(m.x + n.x)/2, m.y};
    point p5 = { }

    strassen(a, b, );
    strassen(a, b, (x + y)/2, y, (x + y)/2);
    strassen(a, b, (x + y)/2, (x + y)/2, z);
    strassen(a, b, )
}

maxtrix power( maxtrix a, int k )
{
    maxtrix ans = E;

    while(k)//快速幂
    {
        if(k & 1 )
            ans = mulit( ans, a );
        k >>= 1;
        a = mulit(a, a);
    }

    return ans;
}

int main()
{
    maxtrix a;
    int k;

    scanf("%d", &N);

    for(int i = 0; i < N; ++i)
        E.m[i][i] = 1;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        scanf("%d", &(a.m[i][j]));

    scanf("%d", &k);

    a = power(a, k);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            printf("%d ", a.m[i][j]);
            if(j == N - 1)
                putchar('\n');
        }

    return 0;
}
