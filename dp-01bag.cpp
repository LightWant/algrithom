//lisÎÊÌâ
//version 1: n^2
//dp : d(i) = {1, d(j) + 1} j(all) < i, A[j] < A[i]
#include <stdio.h>

int lis( int [], int );

int main()
{
    int A[] = {2,1,5,3,6,4,8,9,7};

    printf("%d", lis( A, 9 ));

    return 0;
}

int lis( int A[], int n )
{
    int len = 1;
    int d[n];

    for( int i = 0; i < n; i++ )
    {
        d[i] = 1;

        for( int j = 0; j < i; j++)
            if( A[j] <= A[i] && d[j] + 1 > d[i] )
                d[i] = d[j] + 1;

        if( d[i] > len )
            len = d[i];
    }

    return len;
}

//version 2 : nlog£¨n£©

#include <stdio.h>

int main()
{

}
