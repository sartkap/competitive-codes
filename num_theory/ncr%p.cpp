ll fastexp(ll x,ll a){
    ll res = 1;
    while(a>0){
        if(a&1){
            res = (res*x)%p;
        }
        a=a>>1;
        x=(x*x)%p;
    }
    return res;
}
ll inverse(ll n){
    return fastexp(n,p-2);
}
ll ncr(ll n,ll r){
    if(n<r)return 0;
    ll ans =  (c[n]*inverse(c[r]))%p;
    ans = ans*inverse(c[n-r])%p;
    return ans;
}
ll ncrac(int n,int r){
    if(n==0 && r==0)return 1;
    return (ncr(n%p,r%p)*ncrac(n/p,r/p))%p;
}
