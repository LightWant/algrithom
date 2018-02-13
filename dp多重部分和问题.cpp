#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX_N 100
#define MAX_K 100000

int n;//数列长度
int K;//目标和长度
int a[MAX_N];//值
int m[MAX_N];//个数
//solve 1;
bool dp1[MAX_N + 1][MAX_K + 1];//dp数组


void solve1()
{
    dp1[0][0] = true;

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= K; j++)
            for(int k = 0; k <= m[i] && k * a[i] <= j; k++)
                dp1[i + 1][j] |= dp1[i][j - k * a[i]];

    if(dp1[n][K])
        printf("Yes\n");
    else
        printf("No\n");
}

//solve2
int dp2[MAX_K + 1];

void solve2()
{
    memset(dp2, -1, sizeof(dp2));

    dp2[0] = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= K; j++)
    {
        printf("i %d j %d dp %d\n", i, j, dp2[j]);
        if( dp2[j] >= 0 )
            dp2[j] = m[i];
        else if( j < a[i] || dp2[j - a[i]] <= 0 )
            dp2[j] = -1;
        else
            dp2[j] = dp2[j - a[i]] - 1;
    }

    if(dp2[K] >= 0)
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    scanf("%d%d", &n, &K);

    for(int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &m[i]);

    solve2();

    return 0;
}
