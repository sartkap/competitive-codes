// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2,fma")
// #pragma GCC optimize ("-ffloat-store")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> // order_of_key() ; *( find_by_order() ) -> kth element in set;
// using namespace __gnu_pbds;  // order_of_key(k) -> Number of elements strictly smaller than k
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 ran(seed); // ran() generates a random number

#define ld long double
#define ll long long int
// #define ll int
#define endl '\n'
#define vll vector<ll>
#define vvl vector<vll>
#define pll pair<ll,ll>
#define ppl pair<pll,ll>
#define vpll vector<pll>
#define mp make_pair
#define pb push_back
#define mapll map<ll,ll>
#define fir first
#define sec second
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define fo(i,b) for(i=0;i<b;++i)
#define repa(i,a,b) for(i=a;i<b;++i)
#define repb(i,a,b) for(i=a;i>=b;--i)
#define all(x) (x).begin(), (x).end()
#define s(v) (ll)((v).size())
#define inf 2000000000000000010 
#define mod  1000000007
#define mod1 998244353

#define mul(a,b,m) (((a%m) * 1LL * (b%m))%m)
#define add(a,b,m) (((a)+(b)>=m) ? ((a)+(b)-(m)) : ((a)+(b)))
#define sub(a,b,m) (((a)-(b) <0) ? ((a)-(b)+(m)) : ((a)-(b)))

                            /*DEBUG*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define Time cerr << "Time : " << 1000 * ((double)clock()-start) / (double)CLOCKS_PER_SEC << "ms\n"
#else
#define debug(x...) 
#define Time 
#endif
                        /*END*/
clock_t start = clock();
ll gcd(ll a, ll b) {return (a==0) ? b : gcd(b%a,a);}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll powm(ll a, ll n, ll mod_){ ll p=1; while(n){ if(n%2){ p=mul(p,a,mod_);} n>>=1; a=mul(a,a,mod_);} return p%mod_;} 
ll powi(ll a, ll mod_) {return powm(a,mod_-2,mod_);}
                          /*Code Begins*/

struct FT2{ // Everything is 0-indexed
    ll N, M;
    std::vector<std::vector<ll>> bit;

    FT2(ll n, ll m): N(n), M(m), bit(m,vll(m)){}

    void ass(ll m, ll n){ // m fenwick trees of length n
        N = n;
        M = m;
        bit.assign(m,std::vector<ll>(n));
    }

    void update(ll i, ll idx, ll val){
        for(;idx<N;idx = idx|(idx+1)) {
            bit[i][idx] += val;
        }
    }

    

    ll get(ll i, ll idx){
        ll sum = 0;
        for(;idx>=0; idx = (idx & (idx+1))-1) {
            sum += bit[i][idx];
        }
        return sum ;
    }

    ll query(ll i, ll L, ll R){ // [L,R]
        if(L<=0) return get(i,R);
        return get(i, R) - get(i, L-1);
    }   

    ll query(ll i, ll L){
        return get(i, L);
    }

    ll bin_search(ll i, ll sum){ // Minimum index where prefix sum becomes
        ll l=0, r=N;       // greater than equal to sum. O(log2(n))
        ll mid;            
        while(r-l>=2){
            mid = (l+r)/2;
            if(get(i, mid-1)<sum) l = mid;
            else r=mid; 
        }
        if(get(i, l)>=sum) return l;
        return r;
    }
    ///Binary lifting in idxth Fenwick tree
    ll bin_lift(ll idx, ll sum){ // Minimum index where prefix sum becomes 
        ll pr = 0;       // greater than equal to sum. O(log(n))
        ll pos = 0; 
        ll LOGN = (ll)log2(N);
        for(ll i=LOGN;i>=0;--i){ 
            if(pos + (1LL<<i)-1 < N and pr + bit[idx][pos + (1LL<<i)-1] < sum){
                pr += bit[idx][pos + (1LL<<i)-1];
                pos += (1LL<<i); 
            }
        }
        return pos; 
    }

}; // Everything is 0-indexed, Ranges are - [L,R]
// FT2(n,m) -> m fenwick trees of length n


int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    _cin
    // cout << setprecision(20);
    ll mn, mx;
    ll n, m, k, t, i, j, sum=0, flag=0, cnt=0;
    ll x=0, y=0, z, l=0 , r=0, q;
    int TC=1;
    // cin >> TC;
while(TC--){ 
    


}    
    Time;
    return 0;
}
