// to find all strongly connected components of a directed graph
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
stack<int> st;
stack<int> sta;
vi v[100003];
vi v2[100003];
vi cost(100003);
int min2;
ll sum=0;
ll count2 = 0;
bool visited[100003]={false};
void dfs(int u){
	visited[u]=true;
	for(auto x:v[u]){
		if(!visited[x])dfs(x);
	}
	st.push(u);
	sta.push(u);
}
void dfs2(int u){
	visited[u]=true;
//	cout<<u<<" ";
	for(auto x:v2[u]){
		//cout<<"y"<<x<<" ";
		
		if(!visited[x])dfs2(x);
	}

	min2 = min(min2,cost[u]);
	//if(min2 == cost[u])count2++;
	//cout<<min2<<"\n";
}
void dfs3(int u,int c){
	visited[u]=true;
	for(auto x:v2[u]){
		if(!visited[x])dfs3(x,c);
	}
	if(cost[u]==c)count2++;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	repa(i,1,n+1){
		cin>>cost[i];
	}
	int m,x,y;
	cin>>m;
	rep(i,m){
		cin>>x>>y;
		v[x].pb(y);
		v2[y].pb(x);
	}
	repa(i,1,n+1){
		if(!visited[i]){
			dfs(i);
		}
	}
	rep(i,n+1){
		visited[i]=false;
	}
	//cout<<st.size()<<" ";
	ll ans = 1;
	vi minarr(0);
	while(!st.empty()){
		//cout<<sum<<" ";
		int t = st.top();
		st.pop();
		if(visited[t])continue;
		//cout<<t<<"\n";
		
		min2 = INT_MAX;
		//count2 = 0;
		dfs2(t);
		minarr.pb(min2);
//		cout<<"\n";
		sum+=min2;
		//count2%=mod;
		//ans*=count2;
		//ans%=mod;
	}
	int i=0;
	rep(i,n+1){
		visited[i]=false;
	}
	while(sta.empty() == false){
		int t = sta.top();
		sta.pop();
		if(visited[t])continue;
		count2=0;
		dfs3(t,minarr[i]);
		i++;
		
		ans*=count2;
		//cout<<count2<<" "<<ans;
		ans%=mod;
	}
	cout<<sum<<" "<<ans;
	return 0;
}
