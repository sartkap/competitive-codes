#include<bits/stdc++.h>
// use gp_hash_table<int,int,custom_hash> m;
// in place of map
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define msi map<string,int>
#define mii map<int,int>
#define viip vector<pair<pair<int,int> >,int>
#define mp make_pair
#define vip vector<pair<int,int> >
#define pb push_back 
#define po pop_back
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define s(v) v.size()
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
// This custom_hash is for unordered_map 
// use map<int, int, custom_hash> mp;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
vi v[100005];
bool visited[100005] = {0};
int par[100005];
int h[100005];
int d[100005];
vip v2(0);
void dfs2(int u){
	if(visited[u])return;
	visited[u] = true;
	// cout<<u<<" "<<flush;
	for(auto x:v[u]){	
		// if(x==z)continue;
		// else{
		// cout<<x<<" "<<flush;
		h[u] = min(h[u],h[x]+1);
		// }
	}
	// cout<<"\n";
	for(auto x:v[u]){
		// cout<<
		if(!visited[x])dfs2(x);
	}
}
void dfs(int u){
	// if(u!=1){
	// 	h[u] = h[par[u]] + 1;
	// }
	d[u] = h[u];
	visited[u] = true;
	for(auto x:v[u]){
		if(!visited[x]){
			par[x] = u;
			dfs(x);
			d[u] = min(d[x],d[u]);
			if(d[x] > h[u]){
				v2.pb(mp(x,u));
			}
		}
		else if(x!=par[u]){
			d[u] = min(d[u],h[x]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	int x,y;
	rep(i,m){
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rep(i,100005){
		h[i]=100006;
	}
	par[1] = -1;
	h[1] = 0;
	// repa(i,1,7){
	// 	for(auto x:v[i]){
	// 		cout<<x<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<h[2];
	dfs2(1);
	// repa(i,1,n+1){
	// 	cout<<h[i]<<"  ";
	// }
	rep(i,100005)visited[i]=false;
	dfs(1);
	rep(i,s(v2)){
		cout<<v2[i].fi<<" "<<v2[i].sec<<"\n";
	}
	return 0;
}