// Author : Sarthak Kapoor
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	string s;
	// string to be searched
	cin>>s;
	// text string
	string t;
	cin>>t;
	string kmp = s + "#" + t; // any seperator which cannot occur in the string
	int len = s(kmp);
	vi phi(len,0);
	repa(i,1,len){
		int j = phi[i-1];
		while(j > 0 && kmp[j] != kmp[i]){
			j = phi[j-1];
		}
		if(kmp[i] == kmp[j])j++;
		phi[i] = j;
	}
	vi ans(0);
	int m = s(s);
	repa(i,m+2,len){
		if(phi[i] == m){
			ans.pb(i-2*m);
		}
	}
	rep(i,s(ans)){
		cout<<ans[i]+1<<" ";
	}
	return 0;
}
