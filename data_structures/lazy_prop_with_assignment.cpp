#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int ll
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define pi pair<int,int> 
#define pii pair<pi,int>
#define ull unsigned long long
#define vi vector<int>
#define viip vector<pair<int,pair<int,int> > > 
#define mp make_pair
#define vip vector<pair<int,int> >
#define pb push_back 
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
// #define s(v) v.size()
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll fastexp(ll x,ll a){
    ll res = 1;
    while(a>0){
        if(a&1){
            res = (res*x)%mod;
        }
        a=a>>1;
        x=(x*x)%mod;
    }
    return res;
}
ll inverse(ll n){
    return fastexp(n,mod-2);
}
template <typename T>
void add(T &a, T b){
	a += b;
	if(a >= mod)a -= mod;
}
template <typename T>
void sub(T &a, T b){
	a -= b;
	if(a < 0)a += mod;
}
template <typename T>
void mul(T &a, T b){
	a *= b;
	if(a >= mod)a %= mod;
}
const int maxn = 2e5 + 10;
int n;
vi s(4*maxn);
vi a(maxn);
vi lazy(4*maxn,-1);
void push(int id){
	if(lazy[id] == -1)return;
	lazy[2*id] = lazy[id];
	lazy[2*id+1] = lazy[id];
	s[2*id] = lazy[id];
	s[2*id+1] = lazy[id];
	lazy[id] = -1;
}
void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		s[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid,r);
	s[id] = s[2*id]+s[2*id+1];
}
int sum(int x,int y,int id = 1,int l = 0,int r = n){
	if(x >= r || l >= y){
		return 0;
	}
	if(x <= l && r <= y){
		return s[id];
	}
	push(id);
	int mid = (l+r)/2;
	return sum(x,y,2*id,l,mid) + sum(x,y,2*id+1,mid,r);
}
void update(int x,int y,int val,int id = 1,int l = 0,int r = n){
	if(x >= r || l >= y){
		return;
	}
	if(x <= l && r <= y){
		lazy[id] = val;
		s[id] = val*(r-l);
		return;
	}
	push(id);
	int mid = (l+r)/2;
	update(x,y,val,2*id,l,mid);
	update(x,y,val,2*id+1,mid,r);
	s[id] = s[2*id] + s[2*id+1];
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>n>>q;
	rep(i,n){
		cin>>a[i];
	}
	build();
	while(q--){
		int x;
		cin>>x;
		int l,r;
		cin>>l>>r;
		if(x == 1){
			cout<<sum(l-1,r)<<"\n";
		}
		else{
			int val;
			cin>>val;
			update(l-1,r,val);
		}
	}
	return 0;
}
