#include <bits/stdc++.h>
using namespace std;
int getAns(vector<int> &num,int i,int tar,vector<vector<int>> &dp){
    if(tar==0)return dp[i][tar]=1;
    if(i==0){
        if(num[i]==tar)return dp[i][tar]=1;
        return dp[i][tar]=0;
    }
    if(dp[i][tar]!=-1)return dp[i][tar];
    int notTake=getAns(num,i-1,tar,dp);
    int Take=0;
    if(tar>=num[i])Take=getAns(num,i-1,tar-num[i],dp);
    return dp[i][tar]=notTake+Take;
}
int Tabulation(vector<int> &num,int tar){
    int n=num.size();
    vector<vector<int>> dp(num.size(),vector<int>(tar+1,-1));
    for(int x=0;x<=tar;x++){
        if(num[0]==x)dp[0][x]=1;
        else dp[0][x]=0;
    }
    for(int x=0;x<n;x++)dp[x][0]=1;
    for(int i=1;i<num.size();i++){
        for(int j=0;j<=tar;j++){
            int notTake=dp[i-1][j];
            int Take=0;
            if(j>=num[i])Take=dp[i-1][j-num[i]];
            dp[i][j]=notTake+Take;
        }
    }
    return dp[n-1][tar];
}
int findWays(vector<int> &num, int tar)
{
//     vector<vector<int>> dp(num.size(),vector<int>(tar+1,-1));
//     return getAns(num,num.size()-1,tar,dp);
    return Tabulation(num,tar);
}