#include <bits/stdc++.h>
using namespace std;
int finalAns(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=1e9;
    for(int ind=i;ind<=j;ind++){
        mini=min(mini,cuts[j+1]-cuts[i-1]+finalAns(i,ind-1,cuts,dp)+finalAns(ind+1,j,cuts,dp));
    }
    return dp[i][j]=mini;
    
}
int Tabulation(int n, int c, vector<int> &cuts){
    cuts.push_back(0);cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    for(int i=c;i>0;i--){
        for(int j=1;j<=c;j++){
            if(i>j)continue;
            int mini=1e9;
            for(int ind=i;ind<=j;ind++){
                mini=min(mini,cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j]);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][c];
}
int cost(int n, int c, vector<int> &cuts){
//     vector<vector<int>> dp(c+2,vector<int>(c+2,-1));
//     vector<int> X=cuts;
//     X.push_back(0);
//     X.push_back(n);
//     sort(X.begin(),X.end());
//     return finalAns(1,c,X,dp);
    return Tabulation(n,c,cuts);
}