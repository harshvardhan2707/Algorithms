#include <iostream>
#include<bits/stdc++.h> 
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr1[n];
    cin>>arr1[0];
    cin>>arr1[n-1];
    int low=0,high=n-1-(n+1)%2;
    for(int i=0;i<n-2-(n+1)%2;i++){
        cin>>arr1[(low+high)/2];
        if(high==n-1-(n+1)%2){
            high=(high-low)/2;
            low=0;
    }
    else{
        int x=high;
        high=2*high-low;
        low=x;
    }}
    if(n%2==0) cin>>arr1[n-2];
    for(int i:arr1){
        cout<<i<<" ";
    }
    cout<<"\n";
    int odd,even;
    for(int i=0;i<n;i++){
        if(i%2==0){ even=i;break;
    }}
    for(int i=0;i<n;i++){
        if(i%2==1){ odd=i;break;
    }}
    arr1[max(odd,even)]=arr1[odd]+arr1[even];
    arr1[min(odd,even)]=INT_MIN;
    for(int i:arr1){
        if(i!=INT_MIN)cout<<i<<" ";
    }
    cout<<"\n";
    for(int i=n-1;i>=0;i--){
        if(i%2==0 && arr1[i]!=INT_MIN){ even=i;break;
    }}
    for(int i=n-1;i>=0;i--){
        if(i%2==1 && arr1[i]!=INT_MIN){ odd=i;break;
    }}
    arr1[min(odd,even)]=arr1[even]+arr1[odd];
    arr1[max(odd,even)]=INT_MIN;
    for(int i:arr1){
        if(i!=INT_MIN)cout<<i<<" ";
    }

}