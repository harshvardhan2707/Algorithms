#include <bits/stdc++.h>
using namespace std;
int finalAns(int i,vector<int> &price,int n,vector<vector<int>> &dp){
//     if(n==0)return 0;
    if(i==0){
        return n*price[0];
    }
    if(dp[i][n]!=-1)return dp[i][n];
    int notSelect=finalAns(i-1,price,n,dp);
    int Select=0;
    if(n>=i+1)Select=price[i]+finalAns(i,price,n-(i+1),dp);
    return dp[i][n]=max(Select,notSelect);
}
int Tabulation(vector<int> &price, int n){
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int j=0;j<=n;j++)dp[0][j]=j*price[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            int notSelect=dp[i-1][j];
            int Select=0;
            if(j>=i+1)Select=price[i]+dp[i][j-(i+1)];
            dp[i][j]=max(Select,notSelect);
        }
    }
    return dp[n-1][n];
}
int cutRod(vector<int> &price, int n)
{
//     vector<vector<int>> dp(n,vector<int>(n+1,-1));
// 	return finalAns(n-1,price,n,dp);
    return Tabulation(price,n);
}
