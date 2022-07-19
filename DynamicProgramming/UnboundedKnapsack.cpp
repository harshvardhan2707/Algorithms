#include <bits/stdc++.h>
using namespace std;
int finalAns(int i,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
//     if(w==0)return 0;
    if(i==0){
        return (w/weight[0])*profit[0];
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int notSelect=finalAns(i-1,w,profit,weight,dp);
    int Select=0;
    if(w>=weight[i])Select=profit[i]+finalAns(i,w-weight[i],profit,weight,dp);
    return dp[i][w]=max(Select,notSelect);
}
int Tabulation(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int j=0;j<=w;j++){
        dp[0][j]=(j/weight[0])*profit[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notSelect=dp[i-1][j];
            int Select=0;
            if(j>=weight[i])Select=profit[i]+dp[i][j-weight[i]];
            dp[i][j]=max(Select,notSelect);
        }
    }
    return dp[n-1][w];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
//     vector<vector<int>> dp(n,vector<int>(w+1,-1));
//     return finalAns(n-1,w,profit,weight,dp);
    return Tabulation(n,w,profit,weight);
}
