#include <bits/stdc++.h>
using namespace std;
int finalAnsBetterMethod(vector<int> &prices,int i,int n,bool canBuy,int fee,vector<vector<int>> &dp){
    if(i>=n)return 0;
    if(dp[i][canBuy]!=-1)return dp[i][canBuy];
    if(canBuy){
        int buys=-prices[i]+finalAnsBetterMethod(prices,i+1,n,false,fee,dp);
        int doesntBuy=finalAnsBetterMethod(prices,i+1,n,true,fee,dp);
        return dp[i][canBuy]=max(buys,doesntBuy);
    }
    else{
        int sells=-fee+prices[i]+finalAnsBetterMethod(prices,i+1,n,true,fee,dp);
        int doesntSell=finalAnsBetterMethod(prices,i+1,n,false,fee,dp);
        return dp[i][canBuy]=max(sells,doesntSell);
    }
    
}
int Tabulation(vector<int> &prices,int n,int fee){
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        int buys=-prices[i]+dp[i+1][0];
        int doesntBuy=dp[i+1][1];
        dp[i][1]=max(buys,doesntBuy);
        int sells=-fee+prices[i]+dp[i+1][1];
        int doesntSell=dp[i+1][0];
        dp[i][0]=max(sells,doesntSell);
    }
    return dp[0][1];
}
int spaceOptimization(vector<int> &prices,int n,int fee){
    vector<int> dp(2,0);
    for(int i=n-1;i>=0;i--){
        int buys=-prices[i]+dp[0];
        int doesntBuy=dp[1];
        int X=max(buys,doesntBuy);
        int sells=-fee+prices[i]+dp[1];
        int doesntSell=dp[0];
        int Y=max(sells,doesntSell);
        dp[1]=X;
        dp[0]=Y;
    }
    return dp[1];
}
int maximumProfit(int n, int fee, vector<int> &prices) {
//     vector<vector<int>> dp(n,vector<int>(2,-1));
//     return finalAnsBetterMethod(prices,0,n,true,fee,dp);
    return Tabulation(prices,n,fee);
//     return spaceOptimization(prices,n,fee);
}
