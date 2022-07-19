#include <bits/stdc++.h>
using namespace std;
int finalAnsBetterMethod(vector<int> &prices,int i,int n,bool canBuy,vector<vector<int>> &dp){
    if(i>=n)return 0;
    if(dp[i][canBuy]!=-1)return dp[i][canBuy];
    if(canBuy){
        int buys=-prices[i]+finalAnsBetterMethod(prices,i+1,n,false,dp);
        int doesntBuy=finalAnsBetterMethod(prices,i+1,n,true,dp);
        return dp[i][canBuy]=max(buys,doesntBuy);
    }
    else{
        int sells=prices[i]+finalAnsBetterMethod(prices,i+2,n,true,dp);
        int doesntSell=finalAnsBetterMethod(prices,i+1,n,false,dp);
        return dp[i][canBuy]=max(sells,doesntSell);
    }
    
}
int finalAns(vector<int> &prices,int i,int n,bool canBuy,bool hasCoolDown,vector<vector<vector<int>>> &dp){
    if(i==n)return 0;
    if(dp[i][canBuy][hasCoolDown]!=-1)return dp[i][canBuy][hasCoolDown];
    if(hasCoolDown)return finalAns(prices,i+1,n,canBuy,false,dp);
    if(canBuy){
        long buys=-prices[i]+finalAns(prices,i+1,n,false,hasCoolDown,dp);
        long doesntBuy=finalAns(prices,i+1,n,true,hasCoolDown,dp);
        return dp[i][canBuy][hasCoolDown]=max(buys,doesntBuy);
    }
    else{
        long sells=prices[i]+finalAns(prices,i+1,n,true,true,dp);
        long doesntSell=finalAns(prices,i+1,n,false,hasCoolDown,dp);
        return dp[i][canBuy][hasCoolDown]=max(sells,doesntSell);
    }
    
}
int Tabulation(vector<int> &prices){
        int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(2,0)));
    for(int i=n-1;i>=0;i--){
            dp[i][0][1]=dp[i+1][0][0];
        dp[i][1][1]=dp[i+1][1][0];
            int buys=-prices[i]+dp[i+1][0][0];
        int doesntBuy=dp[i+1][1][0];
        dp[i][1][0]=max(buys,doesntBuy);
        int sells=prices[i]+dp[i+1][1][1];
        int doesntSell=dp[i+1][0][0];
        dp[i][0][0]=max(sells,doesntSell);
    }
    return dp[0][1][0];
}
int SpaceOptimization(vector<int> &prices){
        int n=prices.size();
    vector<vector<int>> dp(2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        int M=dp[0][0],N=dp[1][0];
            int buys=-prices[i]+dp[0][0];
        int doesntBuy=dp[1][0];
        int X=max(buys,doesntBuy);
        int sells=prices[i]+dp[1][1];
        int doesntSell=dp[0][0];
        int Y=max(sells,doesntSell);
        dp[0][0]=M;
        dp[1][1]=N;
        dp[1][0]=X;
        dp[0][0]=Y;
    }
    return dp[1][0];
}
int stockProfit(vector<int> &prices){
//     int n=prices.size();
//     vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
//     return finalAns(prices,0,n,true,false,dp);
//     return Tabulation(prices);
    return SpaceOptimization(prices);
}

int main(){

}