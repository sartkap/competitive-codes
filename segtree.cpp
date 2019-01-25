#include<bits/stdc++.h>
using namespace std;
int n;
void update(int pos,int val,vector<int> &v){
	for(;pos<=n;pos+=(-pos)&(pos)){
		v[pos]+=val;
	}
}
int sum(int pos,vector<int> &v){
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
	return 0;
}
