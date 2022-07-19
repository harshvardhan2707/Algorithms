#include <bits/stdc++.h>
using namespace std;
// Shows why it is important to know tabulation
bool Tabulation(int n,int target,vector<int> &arr,vector<vector<bool>> &dp){
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
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum=0;
    for(auto i:arr)sum+=i;
    vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
    Tabulation(n,sum,arr,dp);
    int minAns=sum;
    for(int i=0;i<=sum;i++){
        if(dp[n-1][i] && minAns>abs(sum-2*i))minAns=abs(sum-2*i);
    }
    return minAns;
    
}
