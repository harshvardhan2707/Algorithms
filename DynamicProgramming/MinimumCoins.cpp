#include <bits/stdc++.h>
using namespace std;
int getAns(vector<int> &num, int i,int target,vector<vector<int>> &dp){
    if(target==0)return 0;
    if(i==0){
        if(target%num[i]==0)return target/num[i];
        return 1e9;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int notTake=getAns(num,i-1,target,dp);
    int Take=1e9;
    if(target>=num[i])Take=1+getAns(num,i,target-num[i],dp);
    return dp[i][target]=min(notTake,Take);
}
int Tabulation(vector<int> &num, int x){
    int n=num.size();
    vector<vector<int>> dp(num.size(),vector<int>(x+1,-1));
    for(int i=0;i<n;i++)dp[i][0]=0;
    for(int target=0;target<=x;target++){
        if(target%num[0]==0)dp[0][target]=target/num[0];
        else dp[0][target]=1e9;
    }
    for(int i=1;i<n;i++){
        for(int target=0;target<=x;target++){
            int notTake=dp[i-1][target];
            int Take=1e9;
            if(target>=num[i])Take=1+dp[i][target-num[i]];
            dp[i][target]=min(notTake,Take);
        }
    }
    return dp[n-1][x];
}
int minimumElements(vector<int> &num, int x)
{
//     vector<vector<int>> dp(num.size(),vector<int>(x+1,-1));
//     int X=getAns(num,num.size()-1,x,dp);
    int X=Tabulation(num,x);
    if(X>=1e9)return -1;
    return X;
}