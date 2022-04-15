#include <bits/stdc++.h>
using namespace std;
void getSubsetSums(vector<int> arr,int N,vector<int> & ans,int sum,int ind){
    if(ind>=N){ans.push_back(sum);return;}
    sum+=arr[ind];
    getSubsetSums(arr,N,ans,sum,ind+1);
    sum-=arr[ind];
    getSubsetSums(arr,N,ans,sum,ind+1);
    
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    getSubsetSums(arr,N,ans,0,0);
    // vector<int> v(ans.begin(),ans.end());
    // v.sort()
    return ans;
}
int main(){
    vector<int> X={10,20,30};
    vector<int> ans=subsetSums(X,3);
    for(auto i:ans)cout<<i<<" ";
}