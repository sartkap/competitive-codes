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
    	// find f[mask] = sum of all a[i] such that i is a subset of mask.
    	// we have to find this for all masks.
    	// number of elements = 2^n
	int n;
	cin>>n;
	int N = (1<<n);
	vi v(N);
	vi f(N,0);
	rep(i,N)cin>>v[i];
	
	// naive approach - O(4^n)
	rep(mask,(1<<n)){
		rep(i,(1<<n)){
			if((mask & i) == i){
				f[mask] += v[i];
			}
		}
	}	
	rep(i,N){
		cout<<f[i]<<" ";
		f[i] = 0;
	}
	cout<<"\n";

	// second approach - O(3^n)
	rep(mask,(1<<n)){
		f[mask] = v[0];
		for(int i = mask;i > 0;i = (i-1)&mask){
			f[mask] += v[i];
		}
	}
	rep(i,N){
		cout<<f[i]<<" ";
		f[i]= 0;
	}
	cout<<"\n";

	// SOS DP approach - O(n*2^n)
	int dp[(1<<n)][n];
	rep(mask,(1<<n)){
		rep(i,n){
			if(mask & (1<<i)){
				if(!i)dp[mask][i] = v[mask] + v[mask ^ (1<<i)];
				else dp[mask][i] = dp[mask][i-1] + dp[mask ^ (1<<i)][i-1];
			}
			else{
				if(!i)dp[mask][i] = v[mask];
				else dp[mask][i] = dp[mask][i-1];
			}
		}
		f[mask] = dp[mask][n-1];
	}
	rep(i,N){
		cout<<f[i]<<" ";
		f[i] = 0;
	}
	cout<<"\n";
	
	// SOS DP Space Optimized Code 
	// -------------------Always Use this---------------------
	rep(i,N)f[i] = v[i];
	rep(i,n){
		rep(mask,(1<<n)){
			if(mask & (1<<i)){
				f[mask] += f[mask ^ (1<<i)];
			}
		}	
	}	
	rep(mask,N){
		cout<<f[mask]<<" ";
	}
	return 0;
}
