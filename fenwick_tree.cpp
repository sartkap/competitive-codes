#include<bits/stdc++.h>
using namespace std;
int n;
void update(int pos,int val,vector<int> &v){//for updation of fenwick tree
	for(;pos<=n;pos+=(-pos)&(pos)){
		v[pos]+=val;
	}
}
int sum(int pos,vector<int> &v){//finds sum from 0 index to pos-1 index both included
	int sum1=0;
	for(;pos>=1;pos-=(-pos)&(pos)){
		sum1+=v[pos];
	}
	return sum1;
}
int main(){
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int> segtree(n+1,0);
	for(int i=1;i<=n;i++){
		update(i,v[i-1],segtree);
	}
	for(int i=1;i<=n;i++){
		cout<<sum(i,segtree)<<' ';
	}
	int l,r;
	cin>>l>>r;
	cout<<sum(r+1,segtree)-sum(l,segtree);//to find sum from [l,r] assuming array is 0 indexed.
	return 0;
}
