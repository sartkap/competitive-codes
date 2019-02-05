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
///////////////////Bellman ford algorithm//////////////
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y,w;
	vip v[n+1];
	vi dis(n+1,100000000);//initially all distances infinte
	dis[1]=0;
	rep(i,m){
		cin>>x>>y>>w;
		v[x].pb(mp(y,w));
		//v[y].pb(mp(x,w));
		//**************************************uncomment for undirected graph but any edge of undirected graph cannot be negative*******************
	}
	repa(i,1,n+1){
		//cout<<i<<"## ";
		for(auto u:v[i]){
			//cout<<u.fi<<u.sec<<" ";
		}
		//cout<<endl;
	}
	///*****Complexity is O(nm) 
	rep(i,n-1){//run (n-1) iterations
		repa(j,1,n+1){
			for(auto u:v[j]){
				dis[u.fi]=min(dis[u.fi],u.sec+dis[j]);
				//cout<<j<<" "<<u.fi<<" "<<dis[u.fi]<<" "<<u.sec<<" "<<dis[j]<<"\n";
			}
		}
	}
	repa(i,1,n+1)cout<<dis[i]<<" ";
	return 0;
}
