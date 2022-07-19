#include <bits/stdc++.h>
using namespace std;
long finalAns(long *values,int i,int n,bool canBuy,vector<vector<long>> &dp){
    if(i==n)return 0;
    if(dp[i][canBuy]!=-1)return dp[i][canBuy];
    if(canBuy){
        long buys=-values[i]+finalAns(values,i+1,n,false,dp);
        long doesntBuy=finalAns(values,i+1,n,true,dp);
        return dp[i][canBuy]=max(buys,doesntBuy);
    }
    else{
        long sells=values[i]+finalAns(values,i+1,n,true,dp);
        long doesntSell=finalAns(values,i+1,n,false,dp);
        return dp[i][canBuy]=max(sells,doesntSell);
    }
    
}
long Tabulation(long *values,int n){
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    for(int i=n-1;i>=0;i--){
        long buys=-values[i]+dp[i+1][0];
        long doesntBuy=dp[i+1][1];
        dp[i][1]=max(buys,doesntBuy);
        long sells=values[i]+dp[i+1][1];
        long doesntSell=dp[i+1][0];
        dp[i][0]=max(sells,doesntSell);
    }
    return dp[0][1];
}
long spaceOptimization(long *values,int n){
    vector<long> dp(2,0);
    for(int i=n-1;i>=0;i--){
        long buys=-values[i]+dp[0];
        long doesntBuy=dp[1];
        long X=max(buys,doesntBuy);
        long sells=values[i]+dp[1];
        long doesntSell=dp[0];
        long Y=max(sells,doesntSell);
        dp[1]=X;
        dp[0]=Y;
    }
    return dp[1];
}
long getMaximumProfit(long *values, int n)
{
//     vector<vector<long>> dp(n,vector<long>(2,-1));
//     return finalAns(values,0,n,true,dp);
    // return Tabulation(values,n);
    return spaceOptimization(values,n);
}
int main(){
    int n;cin>>n;
    long values[n];
    for(int i=0;i<n;i++)cin>>values[i];
    cout<<getMaximumProfit(values,n);
}