#include <bits/stdc++.h>
using namespace std;
bool finalAns(vector<int> &arr,int i,int target,vector<vector<int>> &dp){
    if(target==0)return true;
    if(i==0)return arr[i]==target;
    if(dp[i][target]!=-1)return dp[i][target];
    bool notSelect=finalAns(arr,i-1,target,dp);
    bool Select=false;
    if(target>=arr[i])Select=finalAns(arr,i-1,target-arr[i],dp);
    if(Select||notSelect)return dp[i][target]=true;
    return dp[i][target]=false;
}
bool canPartition(vector<int> &arr, int n)
{
	int sum=0;
    for(auto i:arr){
        sum+=i;
    }
    if(sum%2==1)return false;
    vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
    int k=sum/2;
    for(int j=0;j<=k;j++)dp[0][j]=(arr[0]==j);
    for(int i=1;i<n;i++){
        for(int target=0;target<=k;target++){
            bool notSelect=dp[i-1][target];
            bool Select=false;
            if(target>=arr[i])Select=dp[i-1][target-arr[i]];
            dp[i][target]=Select||notSelect;
        }
    }
//     return finalAns(arr,n-1,sum/2,dp);
    return dp[n-1][k];
}
int main(){

}