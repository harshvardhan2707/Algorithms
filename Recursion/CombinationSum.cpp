#include <bits/stdc++.h>
using namespace std;
void SumAllCombs(int arr[],int n,vector<int> &a,vector<vector<int>> &ans,int sum,int index,int currSum){
    if(currSum>sum)return;
    if(index>=n){
        if(currSum==sum){
            ans.push_back(a);
        }
        return;
    }
    currSum+=arr[index];
    a.push_back(arr[index]);
    SumAllCombs(arr,n,a,ans,sum,index,currSum);
    currSum-=a[a.size()-1];
    a.pop_back();
    SumAllCombs(arr,n,a,ans,sum,index+1,currSum);
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