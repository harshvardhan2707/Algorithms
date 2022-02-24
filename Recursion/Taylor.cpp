#include <bits/stdc++.h>
using namespace std;
double Taylor(int x,int n){
    static double p=1,f=1,r;
    if(n==0) return 1;
    else{
        r=Taylor(x,n-1);
        p*=x;
        f*=n;
        return r+p/f;
    }
}
double TaylorHorner(double x,double n){
    static double s=1;
    if(n==0) return s;
    s=1+(x/n)*s;
    return TaylorHorner(x,n-1);
}
double TaylorLoop(double x,double n){
    double s=1;
    for(int i=n;i>0;i--){
        s=1+(x/i)*s;
    }
    return s;
}
double TaylorLoopEasyMethod(double x,double n){
    double s=1,pow=1,fact=1;
    for(int i=1;i<=n;i++){
        pow*=x;
        fact*=i;
        s+=(pow/fact);
    }
    return s;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<TaylorHorner(3,10)<<" "<<TaylorLoop(3,10)<<" "<<TaylorLoopEasyMethod(3,10);
	return 0;
}