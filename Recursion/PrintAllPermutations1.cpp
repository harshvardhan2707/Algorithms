#include <bits/stdc++.h>
using namespace std;
void getAnswers(vector<int> &nums,vector<bool> X,vector<vector<int>> &ans,vector<int> theOne){
    if(theOne.size()==nums.size()){
        ans.push_back(theOne);return;
    }
    for(int i=0;i<nums.size();i++){
        if(!X[i]){
            X[i]=true;
            theOne.push_back(nums[i]);
            getAnswers(nums,X,ans,theOne);
            X[i]=false;
            theOne.pop_back();
        }
    }
    
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> X(nums.size(),false);
    vector<int> theOne;
    vector<vector<int>> ans;
    getAnswers(nums,X,ans,theOne);
    return ans;
}
int main(){
    vector<int> nums{1,2,3,4};
    vector<vector<int>> ans=permute(nums);
    for(auto i:ans){
        for(auto j:i)cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}