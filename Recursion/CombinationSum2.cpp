#include <bits/stdc++.h>
using namespace std;
void sumCombNoDuplicates(int arr[],int n,int target,vector<int> &a,vector<vector<int>> &ans,int index){
    if(target<0)return;
    if(target==0){ans.push_back(a);return;}
    if(index>=n){
    return;
    }
    for(int i=index;i<n;i++){
        if(i>index && arr[i]==arr[i-1])continue;
        if(arr[i]>target)break;
        a.push_back(arr[i]);
        sumCombNoDuplicates(arr,n,target-arr[i],a,ans,index+1);
        a.pop_back();
    }
}
int main(){

}