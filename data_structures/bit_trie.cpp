// Author : Sarthak Kapoor
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
typedef struct data{
	data* bit[2];
	int cnt = 0;
}trie;
trie* head;
// insert x into trie
void insert(int x){
	trie *cur = head;
	repr(i,31){
		int b = (x>>i) & 1;
		if(!cur->bit[b]){
			cur->bit[b] = new trie();
		}
		cur = cur->bit[b];
		cur->cnt++;
	}
}
// remove one occurance of x from trie
void remove(int x){
	trie *cur = head;
	repr(i,31){
		int b = (x>>i) & 1;
		cur = cur->bit[b];
		cur->cnt--;
	}
}
// max xor of any element in trie with given value 'x'
int maxxor(int x){
	trie *cur = head;
	int ans = x;
	repr(i,31){
		int b = (x>>i) & 1;
		int n = b^1;
		trie *temp = cur;
		if(temp->bit[n] && temp->bit[n]->cnt > 0){
			ans = ans | (1<<i);
			// ans += (1<<i);
			cur = temp->bit[n];
		}
		else{
			int c = ~(1<<(i));
			ans = ans & c;
			// ans = ans ^ (1>>b);
			cur = cur->bit[b];
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	int q;
	cin>>q;
	head = new trie();
	insert(0);
	while(q--){
		char x;
		int y;
		cin>>x>>y;
		if(x == '+')insert(y);
		else if(x == '-')remove(y);
		else cout<<maxxor(y)<<"\n";
	}
	return 0;
}
