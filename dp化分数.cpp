//dp[i][j] = dp[i][j - i] + dp[i - 1][j]
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

int main()
{
    int n, m;
    int dp[MAX_N + 1][MAX_N + 1];

    //fill(dp, dp + n, 0);
    dp[0][0] = 0;

    cin >> n >> m;

    for(int = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
    {
        dp[i][j] = dp[i][j - 1] + dp[]
    }
}
