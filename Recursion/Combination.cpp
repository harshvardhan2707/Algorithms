#include <bits/stdc++.h>
using namespace std;
int C(int n,int r){
    if(r==0|| n==r)return 1;
    return C(n-1,r-1)+C(n-1,r);
}
long long CLoop(int n,int r){
    if(r==0|| n==r) return 1;
    long long x=1,y,z;
    for(int i=1;i<=n;i++){
        x*=i;
        if(i==r)y=x;
        if(i==n-r)z=x;
    }
    return x/(y*z);
    
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<C(15,7)<<" "<<CLoop(15,7);
	return 0;
}