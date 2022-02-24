#include <bits/stdc++.h>
using namespace std;
int fib(int target,int term1,int term2){
    cout<<term1<<" ";
    if(target==0){
        return term1+term2;
    }
    else{
        fib(target-1,term2,term1+term2);
    }
}
int fibMemoization(int s,int arr[]){
    if(s<=1){
        arr[s]=s;
        return s;
    }
    if(arr[s-1]==0){
        arr[s-1]=fibMemoization(s-1,arr);
    }
    if(arr[s-2]==0){
        arr[s-1]=fibMemoization(s-1,arr);
    }
    return arr[s-1]+arr[s-2];
}
int fibMemoization(int s){
    int arr[s+1]={0};
    return fibMemoization(s,arr);
}
int fibIter(int n){
    if(n<=1) return n;
    int t0=0,t1=1,s;
    for(int i=2;i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<fibMemoization(20);
	return 0;
}