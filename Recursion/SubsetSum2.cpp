#include <bits/stdc++.h>
using namespace std;
void getAllSubsets(vector<int>& nums,vector<vector<int>> &ans,vector<int> &X,int index){
    ans.push_back(X);
    for(int i=index;i<nums.size();i++){
        if(i>index && nums[i]==nums[i-1])continue;
        X.push_back(nums[i]);
        getAllSubsets(nums,ans,X,i+1);
        X.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    vector<int> X;
    getAllSubsets(nums,ans,X,0);
    return ans;
}
int main(){
    
}