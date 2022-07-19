#include <bits/stdc++.h>
using namespace std;
bool getAnswer(int i,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(target==0)return true;
    if(i==0)return arr[i]==target;
    if(dp[i][target]!=-1)return dp[i][target]==1;
    bool notSelect=getAnswer(i-1,target,arr,dp);
    bool Select=false;
        if(target>=arr[i])Select=getAnswer(i-1,target-arr[i],arr,dp);
    if(notSelect||Select)dp[i][target]=1;
    else dp[i][target]=0;
    return dp[i][target]==1;
}
bool Tabulation(int n,int target,vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(target+1,0));
    for(int i=0;i<n;i++)dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notSelect=dp[i-1][j];
            bool Select=false;
            if(j>=arr[i])Select=dp[i-1][j-arr[i]];
            dp[i][j]=notSelect|Select;
        }
    }
    return dp[n-1][target];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return getAnswer(n-1,k,arr,dp);
}
int main(){
    
}