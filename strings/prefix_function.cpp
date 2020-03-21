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
    	//// calculates prefix function of a string defined as -
    	/// π[i]=  max{k:s[0…k−1]=s[i−(k−1)…i]} where k varies from [1,i]
	string s;
	cin>>s;
	int n = s(s);
	vi pi(n);
	pi[0] = 0;
	// O(n^3) naive solution.....
	// rep(i,n){
	// 	rep(j,i){
	// 		if(s.substr(0,j+1) == s.substr(i-j,j+1)){
	// 			pi[i] = j+1;
	// 		}
	// 	}
	// }
	// rep(i,n){
	// 	cout<<pi[i]<<" ";
	// 	pi[i] = 0;
	// }
	// cout<<"\n";

	// O(n) KMP solution .... 
		repa(i,1,n){
			int j = pi[i-1];
			while(j > 0 && s[i] != s[j]){
				j = pi[j-1];
			}
			if(s[i] == s[j])j++;
			pi[i] = j;
		}
		rep(i,n){
			cout<<pi[i]<<' ';
		}
	return 0;
}
