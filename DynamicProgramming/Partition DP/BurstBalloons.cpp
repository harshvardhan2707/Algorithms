#include <bits/stdc++.h>
using namespace std;
int FinalAns(vector<int> &a,int i,int j,vector<vector<int>> &dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int Cost=-1e9;
    for(int ind=i;ind<=j;ind++){
        Cost=max(Cost,a[i-1]*a[ind]*a[j+1]+FinalAns(a,i,ind-1,dp)+FinalAns(a,ind+1,j,dp));
    }
    return dp[i][j]=Cost;
}
int Tabulation(vector<int> &a){
    int n=a.size();
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    a.insert(a.begin(),1);
    a.push_back(1);
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            int Cost=-1e9;
            for(int ind=i;ind<=j;ind++){
                Cost=max(Cost,a[i-1]*a[ind]*a[j+1]+dp[i][ind-1]+dp[ind+1][j]);
            }
            dp[i][j]=Cost;
        }
    }
    return dp[1][n];
}
int maxCoins(vector<int>& a)
{
//     int n=a.size();
//     vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
// 	a.insert(a.begin(),1);
//     a.push_back(1);
//     return FinalAns(a,1,n,dp);
    return Tabulation(a);
}