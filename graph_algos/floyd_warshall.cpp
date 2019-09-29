#include<bits/stdc++.h>
// #include &lt;bits/stdc++.h&gt;
// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// use gp_hash_table<int,int,custom_hash> m;
// in place of map
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
#define vi vector<ll>
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
// This custom_hash is for unordered_map 
// use map<int, int, custom_hash> mp;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int d[100][100];
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int n,m;
vip v[1000];
const int inf = 1e8;
void floyd(){
    repa(k,1,n+1){
        repa(i,1,n+1){
            repa(j,1,n+1){
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    int x,y,z;
    rep(i,m){
        cin>>x>>y>>z;
        v[x].pb(mp(y,z));
    }
    repa(i,1,n+1){
        repa(j,1,n+1){
            d[i][j]=inf;
        }
    }
    repa(i,1,n+1){
        d[i][i]=0;
        for(auto x:v[i]){
            d[i][x.fi] = x.sec;
        }
    }
    floyd();
    repa(i,1,n+1){
        repa(j,1,n+1){
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}

