ll mul(ll a, ll b){
    ll ans = 0;
    while(b){
        if(b & 1) ans = (ans + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ans;
}
ll qpow(ll a,ll b){
    ll ans = 1;
    ll base = a % p;
    while(b){
        if(b & 1) ans = mul(ans, base) % p;
        base = mul(base, base) % p;
        b >>= 1;
    }
    return ans;
}
