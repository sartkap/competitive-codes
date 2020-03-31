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
// for lowercase letters only 
typedef struct data{
	int cnt = 0;
	int isEndOfWord = 0;
	data* arr[26];
}trie;
trie* head;
void insert(string s){
	trie* cur = head;
	rep(i,s(s)){
		int x = s[i] - 'a';
		if(!cur->arr[x]){
			cur->arr[x] = new trie();
		}
		cur = cur->arr[x];
		cur->cnt++;
	}	
	cur->isEndOfWord++;
}
bool search(string s){
	trie* cur = head;
	rep(i,s(s)){
		int x = s[i]-'a';
		if(cur->arr[x] && cur->arr[x]->cnt > 0){
			cur = cur->arr[x];
		}
		else{
			return false;
		}
	}
	if(cur->isEndOfWord > 0)return true;
	return false;
}
void remove(string s){
	// check if the string is present inside the trie
	bool check = search(s);
	// and return if not
	if(!check)return;
	trie* cur = head;
	rep(i,s(s)){
		int x = s[i] - 'a';
		cur = cur->arr[x];
		cur->cnt--;
	}
	cur->isEndOfWord--;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	head = new trie();
	int n;
	cin>>n;
	string s;
	rep(i,n){
		cin>>s;
		insert(s);
	}
	cin>>s;
	// remove(s);
	// remove(s);
	// remove(s);
	// remove(s);
	cout<<search(s);
	return 0;
}
