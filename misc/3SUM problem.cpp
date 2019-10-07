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
    int key;
    int k;
    int low,high,flag=0;
    for(k=0;k<n;k++){
        key=x-a[k];
        low=0;
        high=n-1;
        while(low<high){
            if(low==k){low++;continue;}
            if(high==k){high--;continue;}
            if(a[low]+a[high]==key){
                flag=1;
                break;
            }
            else if(a[low]+a[high]<key){
                low++;
            }
            else if(a[low]+a[high]>key){
                high--;
            }
        }
        if(flag)break;
    }
    if(flag==0)cout<<"Not found";
    else cout<<k<<endl<<low<<endl<<high;
    return 0;
}
