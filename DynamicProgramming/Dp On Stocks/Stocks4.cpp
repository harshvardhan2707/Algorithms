#include <bits/stdc++.h>
using namespace std;
int finalAns(vector<int> &prices, int i, int n,int k,bool canBuy,int no,vector<vector<vector<int>>> &dp){
    if(i==n)return 0;
    if(no==k)return 0;
    if(dp[i][canBuy][no]!=-1)return dp[i][canBuy][no];
    if(canBuy){
        int buys=-prices[i]+finalAns(prices,i+1,n,k,false,no,dp);
        int doesntBuy=finalAns(prices,i+1,n,k,true,no,dp);
        return dp[i][canBuy][no]=max(buys,doesntBuy);
    }
    int sells=prices[i]+finalAns(prices,i+1,n,k,true,no+1,dp);
    int doesntSell=finalAns(prices,i+1,n,k,false,no,dp);
    return dp[i][canBuy][no]=max(sells,doesntSell);
}
int Tabulation(vector<int>& prices, int n,int k){
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int j=k-1;j>=0;j--){
        int buys=-prices[i]+dp[i+1][0][j];
        int doesntBuy=dp[i+1][1][j];
        dp[i][1][j]=max(buys,doesntBuy);
        int sells=prices[i]+dp[i+1][1][j+1];
        int doesntSell=dp[i+1][0][j];
        dp[i][0][j]=max(sells,doesntSell);
        }
    }
    return dp[0][1][0];
}
int SpaceOptimization(vector<int>& prices, int n,int k){
        vector<vector<int>> dp(2,vector<int>(k+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=k-1;j>=0;j--){
        int buys=-prices[i]+dp[0][j];
        int doesntBuy=dp[1][j];
            int X=max(buys,doesntBuy);
        int sells=prices[i]+dp[1][j+1];
        int doesntSell=dp[0][j];
            int Y=max(sells,doesntSell);
            dp[1][j]=X;dp[0][j]=Y;
        }
    }
    return dp[1][0];
}
int maximumProfit(vector<int> &prices, int n, int k)
{
//     return SpaceOptimization(prices,n,k);
//     return Tabulation(prices,n,k);
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
    return finalAns(prices,0,n,k,true,0,dp);
}
int main(){
    
}
