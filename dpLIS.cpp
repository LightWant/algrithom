#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 10001
#define INF 1<<30

int main()
{
    int a[MAX_N];
    int n;
    int dp[MAX_N];
    //for(int i = 0; i < n; i++)
    //    a[i] = INF;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    fill(dp, dp + n, INF);

    for(int i = 0; i < n; i++)
        *lower_bound(dp, dp + n, a[i]) = a[i];

    cout << lower_bound(dp, dp + n, INF) - dp;

    return 0;
}
