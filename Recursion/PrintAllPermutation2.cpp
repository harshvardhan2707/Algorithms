#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int x=a;
    a=b;
    b=x;
}
void getAnswers(vector<int> &nums,vector<vector<int>> &ans,int index){
    if(index>=nums.size()){
        ans.push_back(nums);return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        getAnswers(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }
    
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    getAnswers(nums,ans,0);
    return ans;
}
int main(){
    vector<int> nums{1,2,3};
    vector<vector<int>> ans=permute(nums);
    for(auto i:ans){
        for(auto j:i)cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}