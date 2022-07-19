#include <bits/stdc++.h>
using namespace std;
long finalAns(int *denominations, int i, int value,vector<vector<long>> &dp){
    if(value==0)return 1;
    if(i==0){
        if(value%denominations[0]==0)return 1;
        return 0;
    }
    if(dp[i][value]!=-1)return dp[i][value];
    long notSelect=finalAns(denominations,i-1,value,dp);
    long Select=0;
    if(value>=denominations[i])Select=finalAns(denominations,i,value-denominations[i],dp);
    return dp[i][value]=Select+notSelect;
}
long Tabulation(int *denominations, int n, int value){
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    for(long i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(long j=0;j<=value;j++){
        if(j%denominations[0]==0)dp[0][j]=1;
         else dp[0][j]=0;
    }
    for(long i=1;i<n;i++){
        for(long j=0;j<=value;j++){
            long notSelect=dp[i-1][j];
            long Select=0;
            if(j>=denominations[i])Select=dp[i][j-denominations[i]];
            dp[i][j]=Select+notSelect;
        }
    }
    return dp[n-1][value];
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
//     vector<vector<long>> dp(n,vector<long>(value+1,-1));
//     return finalAns(denominations,n-1,value,dp);
    return Tabulation(denominations,n,value);
}