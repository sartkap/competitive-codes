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
vi v[10000];
vi dis(10000);
vector<bool> visited(10000,false);
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y;
	rep(i,m){
		cin>>x>>y;
		v[x].pb(y);
	}
	queue<int> q;
	q.push(1);
	dis[1]=0;
	while(!(q.empty())){//for connected graph only
		//visited[q.front()]=true;
		//*********process node as q.front()*********//
		cout<<q.front();
		for(auto u:v[q.front()]){
			if(visited[u])continue;
			visited[u]=true;
			q.push(u);
			dis[u]=dis[q.front()]+1;
		}
		q.pop();
	}
	cout<<endl;
	repa(i,1,n+1){
		cout<<dis[i]<<" ";
	}	
	return 0;
}
