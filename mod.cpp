#include <stdio.h>

typedef long long ll;

ll mod_mull( ll a, ll b, ll n )
{
    ll res = 0;
    a %= n;

    while( b )
    {
        if( b & 1 )
            res = ( res + a ) % n;

        a = ( a + a ) % n;

        b >>= 1;
    }

    return res;
}

ll mod_exp( ll a, ll b, ll n )//指数降解为乘
{
    int res = 1;
    a %= n;

    while( b )
    {
        if( b & 1 )
            res = ( res * a ) % n;//or call mod_mull

        a = ( a * a ) % n;

        b >>= 1;
    }

    return res;
}

int main()
{
    ll a, b, n;

    scanf("%lld%lld%lld", &a, &b, &n);

    printf("%lld %lld", mod_mull( a, b, n ), mod_exp( a, b, n ));
}



