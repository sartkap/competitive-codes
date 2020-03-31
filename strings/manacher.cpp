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
ll fastexp(ll x,ll a){
    ll res = 1;
    while(a>0){
        if(a&1){
            res = (res*x)%mod;
        }
        a=a>>1;
        x=(x*x)%mod;
    }
    return res;
}
ll inverse(ll n){
    return fastexp(n,mod-2);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	int n;
	string s;
	cin>>s;
	n = s(s);
	// d1[i] number of palindromes centered at position i of odd length
	// d2[i] "   "    "             "        "          "    even length
	vi d1(n);
	vi d2(n);
	// naive algorithm to calculate d1 and d2
	// rep(i,n){
	// 	d1[i] = 1;
	// 	while(i - d1[i] >= 0 && i+d1[i] < n && s[i-d1[i]] == s[i+d1[i]]){
	// 		d1[i]++;
	// 	}
	// 	d2[i] = 0;
	// 	while(i - d2[i] - 1 >= 0 && i+d2[i] < n && s[i-d2[i] - 1] == s[i+d2[i]]){
	// 		d2[i]++;
	// 	}
	// }	
	// rep(i,n){
	// 	cout<<d1[i]<<' ';
	// }
	// cout<<"\n";
	// rep(i,n){
	// 	cout<<d2[i]<<' ';
	// 	d1[i] = d2[i] = 0;
	// }

	
	// O(n) algorithm to calculate d1 and d2
	// (l,r) is the palindrome found so far with the largest value of r
	// for d1[i];
	for(int i=0,l=0,r = -1;i<n;i++){
		int k = (i > r) ? 1 : min(d1[l+r-i],r-i+1);
		while(i-k >= 0 && i+k < n && s[i-k] ==  s[i+k]){
			k++;
		}
		d1[i] = k--;
		if(i + k > r){
			l = i - k;
			r = i + k;
		}
	}

	// for d2[i]
	for(int i = 0,l=0,r=-1;i<n;i++){
		int k = (i > r) ? 0 : min(d2[l+r-i+1],r-i+1);
		while(i-k-1 >=0 && i+k < n && s[i-k-1] == s[i+k]){
			k++;
		}	
		d2[i]=k++;
		if(i+k > r){
			l=i-k-1;
			r=i+k;
		}	
	}
	rep(i,n){
		cout<<d1[i]<<" ";
	}
	cout<<"\n";
	rep(i,n){
		cout<<d2[i]<<" ";
	}
	return 0;
}
