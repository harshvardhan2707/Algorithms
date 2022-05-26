#include <bits/stdc++.h>
using namespace std;
int finalOutput(vector<int> &nums,int index,vector<int> &X){
	if(index==0){X[0]=nums[0];return X[0];}
	if(index<0)return 0;
	if(X[index]!=-1)return X[index];
	int pick=nums[index]+finalOutput(nums,index-2,X);
	int notPick=0+finalOutput(nums,index-1,X);
	return X[index]=max(pick,notPick);
	
}
int tabulation(vector<int> &nums){
	vector<int> X(nums.size(),-1);
	X[0]=nums[0];
	for(int i=1;i<nums.size();i++){
		int pick=nums[i];
		if(i>1)pick+=X[i-2];
		int notPick=0+X[i-1];
		X[i]=max(pick,notPick);
	}
	return X[nums.size()-1];
}
int spaceOptimization(vector<int> &nums){
	for(int i=1;i<nums.size();i++){
		int pick=nums[i];
		if(i>1)pick+=nums[i-2];
		int notPick=0+nums[i-1];
		nums[i]=max(pick,notPick);
	}
	return nums[nums.size()-1];
}
int spaceOptimizationwithoutVarChange(vector<int> &nums){
    int prev=nums[0],prev2=0,curr=0;
	for(int i=1;i<nums.size();i++){
		int pick=nums[i];
		if(i>1)pick+=prev2;
		int notPick=0+prev;
		curr=max(pick,notPick);
        prev2=prev;prev=curr;
	}
	return prev;
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> X(nums.size(),-1);
	return finalOutput(nums,nums.size()-1,X);
}
int main(){
    vector<int> X{1,2,3,4,5,6,7,2,12,5};
    cout<<maximumNonAdjacentSum(X);
}