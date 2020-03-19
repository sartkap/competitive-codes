// Author : Sarthak Kapoor
//  //                lazy prop with support of sum(l,r) and increase(v,l,r) in O(log N)
#include<bits/stdc++.h>
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
#define viip vector<pair<int,pair<int,int> > > 
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int n;
const int maxn = 1e5 + 2;
int s[4*maxn];
int lazy[4*maxn];
int a[maxn];
void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		s[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid,r);
	s[id] = s[2*id] + s[2*id+1];
}
void upd(int id,int l,int r,int x){
	lazy[id] += x;
	s[id] += (r-l)*x;
}
void shift(int id,int l,int r){
	int mid = (l+r)/2;
	upd(2*id,l,mid,lazy[id]);
	upd(2*id+1,mid,r,lazy[id]);
	lazy[id] = 0;
}
void update(int v,int x,int y,int id = 1,int l = 0,int r = n){
	if(x >= r || l >= y)return;
	if(x <= l && r <= y){
		upd(id,l,r,v);
		return;
	}
	shift(id,l,r);
	int mid = (l+r)/2;
	update(v,x,y,2*id,l,mid);
	update(v,x,y,2*id+1,mid,r);
	s[id] = s[2*id] + s[2*id+1];
}
int sum(int x,int y,int id = 1,int l = 0,int r = n){
	if(y <= l || r <= x)return 0;
	if(x <= l && r <= y)return s[id];
	shift(id,l,r);
	int mid = (l+r)/2;
	return sum(x,y,2*id,l,mid) + sum(x,y,2*id+1,mid,r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin>>n;
    rep(i,n){
    	cin>>a[i];
    }
    build();
    int q;
    cin>>q;
    while(q--){
    	int x;
    	cin>>x;
    	if(x == 1){ // update
    		int l,r,p;
    		cin>>l>>r>>p;
    		update(p,l-1,r);
    	}	
    	else{ // sum
    		int l,r;
    		cin>>l>>r;
    		cout<<sum(l-1,r)<<"\n";
    	}
    }
  	return 0;
}
