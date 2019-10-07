#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vil vector<pair<ll,ll> >
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
vector<int> parent;
vector<int> rank1;
int flag=0;
struct union_find {
	
	union_find(int n){
		parent = vector<int>(n);
		rank1 = vector<int>(n);
		rep(i,n){
			parent[i]=i;
			rank1[i]=0;
		}
	}
};
int find(int x){
	if(parent[x] == x){
		return x;
	}
	else{
		parent[x]=find(parent[x]);
		return parent[x];
	}
}
void unite(int x,int y){
	if(parent[find(x)] == find(y)){
		flag=-1;
		return;
	}
	
	int par1 = find(x);
	int par2 = find(y);
	if(par1==par2){
		return;
	}
	else if(rank1[par1]<rank1[par2]){
		parent[par1] = par2;
	}
	else if(rank1[par2]<rank1[par1]){
		parent[par2] = par1;
	}
	else{
		parent[par1] = par2;
		rank1[par2] += 1;
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
	int t;
	cin>>t;
	int x,y;
	while(t--){
		int n,m;
		cin>>n>>m;
		flag=0;
		union_find w(n+1);
		int max1 = 0;
		rep(i,m){
			cin>>x>>y;
			unite(x,y);
		}
		if(flag==-1){
			cout<<"Cycle\n";
		}
		else{
			cout<<"No Cycle\n";
		}
		parent.clear();
		rank1.clear();
	}
	return 0;
}
