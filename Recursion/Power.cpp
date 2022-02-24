#include <bits/stdc++.h>
using namespace std;
int power(int x,int y){
    if(y>0) return power(x,y-1)*x;
    return 1;
}
int power1(int x,int y){
    int ans=x;
    while(y-->1){
        ans*=x;
    }
    return ans;
}
int fasterPower(int x,int y){
    if(y>0){
        if(y%2==0) return fasterPower(x*x,y/2);
        else return fasterPower(x*x,(y-1)/2)*x;
    }
    return 1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<power(2,9)<<" "<<power1(2,9)<<" "<<fasterPower(2,9);
	return 0;
}