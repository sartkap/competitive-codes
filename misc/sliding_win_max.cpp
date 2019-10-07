//prints the maximum of every k consecutive elements in a vector
//sliding window minimum
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
int main() {//**************assumes k<=n always******************//
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	vi v(n);
	rep(i,n)cin>>v[i];
	deque<int> q(k);
	rep(i,n){
		while((!q.empty()) && v[i]>=v[q.back()])q.po();
		q.pb(i);
	}
	cout<<v[q.front()]<<" ";
	repa(i,k,n){
		while((!q.empty()) && q.front()+k<=i)q.pop_front();
		while((!q.empty()) && v[i]>=v[q.back()])q.po();
		q.pb(i);
		cout<<v[q.front()]<<" ";
	}


	return 0;
}
