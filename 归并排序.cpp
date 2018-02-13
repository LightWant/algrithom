#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
#define MAXN 1000000
int a[MAXN], temp[MAXN], sum = 0;

void mergearray(int first, int mid, int last)
{
    memset(temp, 0, sizeof(temp));
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 1;

    while (i <= m && j <= n)
    {
        if (a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= n) temp[k++] = a[j++];
    for (i = 1; i < k; i++) a[first + i - 1] = temp[i];
}

void mergesort(int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(first, mid);
        mergesort(mid + 1, last);
        mergearray(first, mid, last);
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        sum = 0;
        int i, j;
        for (i = 1; i <= n; i++) scanf("%d", &a[i]);
        mergesort(1, n);
        for (i = 1; i <= n; i++) printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}
