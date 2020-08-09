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
#define pi pair<int,int> 
#define pii pair<pi,int>
#define ull unsigned long long
#define vi vector<int>
#define viip vector<pair<int,pair<int,int> > > 
#define mp make_pair
#define vip vector<pair<int,int> >
#define pb push_back 
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
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
template <typename T>
void add(T &a, T b){
	a += b;
	if(a >= mod)a -= mod;
}
template <typename T>
void sub(T &a, T b){
	a -= b;
	if(a < 0)a += mod;
}
template <typename T>
void mul(T &a, T b){
	a *= b;
	if(a >= mod)a %= mod;
}
vector<vector<int> > res;
void suffix_array(string s){
	// the element that is being added here must have
	// lower ASCII value than all other characters in string.
	s.pb('$');
	int n = s(s);
	vi p(n),c(n);
	vector<pair<char,int> > a;
	rep(i,n){
		a.pb({s[i],i});
	}
	sort(all(a));
	// vi p(n);
	rep(i,n){
		p[i] = a[i].sec;
	}
	c[p[0]] = 0;
	repa(i,1,n){
		if(a[i].fi == a[i-1].fi){
			c[p[i]] = c[p[i-1]];
		}
		else{
			c[p[i]] = c[p[i-1]] + 1;
		}
	}
	res.pb(c);
	// rep(i,s(c)){
	// 	cout<<c[i]<<" ";
	// }
	// cout<<"\n";
	// operation for k = 0 (base case completed)
	int k = 0;
	while((1<<k) < n){
		vector<pair<pair<int,int>,int > > b(n);
		rep(i,n){
			b[i] = {{c[i],c[(i+(1<<k))%n]},i};
		}
		sort(all(b));
		rep(i,n){
			p[i] = b[i].sec;
		}
		c[p[0]] = 0;
		repa(i,1,n){
			if(b[i].fi == b[i-1].fi){
				c[p[i]] = c[p[i-1]];
			}
			else{
				c[p[i]] = c[p[i-1]] + 1;
			}
		}
		k++;
		// c[i] contains the number, suffix starting from 'i' would  
		// get if all suffixes are sorted in lexicographic order 
		// only considering the first (1<<k) elements in the cyclic suffixes
		
		res.pb(c);
		
		// rep(i,s(c)){
		// 	cout<<c[i]<<" ";
		// }
		// cout<<"\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;;
	cin>>s;
	suffix_array(s);
	vi ans = res.back();
	// ans[i] contains the number, suffix starting from 'i' would  
	// get if all suffixes are sorted in lexicographic order
	vip fin;
	rep(i,s(ans)){
		fin.pb({ans[i],i});
	}
	sort(all(fin));

	// fin.sec is the final suffix array
	rep(i,s(ans)){
		cout<<fin[i].sec<<" ";
	}
	return 0;
}
