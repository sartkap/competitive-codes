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
vi v(0);
vi a(0);
int n;
void build(){
	rep(i,n)v[i+n]=a[i];
	repba(i,n-1,1)v[i]=v[i<<1]+v[i<<1|1];
}
void update(int p,int val){
	v[p+n]=val;
	p+=n;
	for(int i=p;i>1;i>>=1)v[i>>1]=v[i]+v[i^1];
}
int sum(int l,int r){
	int ans=0;
	for(l+=n, r+=n;l<r; l>>=1,r>>=1){
		if(l&1)ans+=v[l++];
		if(r&1)ans+=v[--r];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int x;
	rep(i,n){cin>>x;a.pb(x);v.pb(0);}
	rep(i,n)v.pb(0);
	build();
	repa(i,1,2*n){cout<<v[i]<<" ";}
	update(2,9);
	cout<<endl;
	repa(i,1,2*n){cout<<v[i]<<" ";}
	cout<<endl;
	cout<<sum(2,4);
	return 0;	
}
