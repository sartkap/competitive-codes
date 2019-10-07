#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    int a[n];
    REP(i,n){
        cin>>a[i];
    }
    int p1=0;
    int p2=0;
    int sum=a[0];
    int flag=0;
    while(!(p1==n-1 && p2==n-1)){
        if(sum<x){
            if(p2!=n-1){p2++;sum+=a[p2];}
            else break;
        }
        else if(sum==x){
            flag=1;
            break;
        }
        else if(p1==p2){
            p1++;
            sum=a[p1]-a[p2];
            p2++;
        }
        else{
            if(p1!=n-1){p1++;sum-=a[p1-1];}
            else break;
        }
    }
    if(flag==0)cout<<"Not found";
    else cout<<p1<<" "<<p2;
    return 0;
}
