#include <bits/stdc++.h>
using namespace std;
void SumAllCombs(int arr[],int n,vector<int> &a,vector<vector<int>> &ans,int sum,int j,int s){
    if(s>sum)return;
    if(j>=n){
        if(s==sum){
            ans.push_back(a);
        }
        return;
    }
    s+=arr[j];
    a.push_back(arr[j]);
    SumAllCombs(arr,n,a,ans,sum,j,s);
    s-=a[a.size()-1];
    a.pop_back();
    SumAllCombs(arr,n,a,ans,sum,j+1,s);
}
int main(){
    int arr[]={2,3,4,7};
    vector<int> a;
    vector<vector<int>> ans;
    SumAllCombs(arr,4,a,ans,7,0,0);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}