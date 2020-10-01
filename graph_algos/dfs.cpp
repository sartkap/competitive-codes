#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repa(i,a,n) for(int i=a;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define repba(i,b,a) for(int i=b;i>=a;i--)
#define repab(i,a,b) for(int i=a;i<b;i++)
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
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int max_si = 10000;
vi adj[10000];
vector<bool> vis(max_si,false);
void dfs(int u){
	if(vis[u])return;
	vis[u]=true;
	//**************place to process node
	cout<<u; // optional: remove before submitting, if something else processed
	for(auto neigh:adj[u]){
		dfs(neigh);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y;
	rep(i,m){
		cin>>x>>y;
		adj[x].pb(y);
	}
	int cnt = 0; // count of unconnected components
	repa(i,1,n+1){//*********so that no node is left
		
		if(!vis[i]){ cnt++; dfs(i);}
	}
	dfs(1);
	return 0;
}
