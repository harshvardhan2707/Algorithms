#include <bits/stdc++.h>
using namespace std;
int getAns(vector<int> weight, vector<int> value, int i, int Wt,vector<vector<int>> &dp){
    if(Wt==0)return 0;
    if(i==0){
        if(weight[0]<=Wt)return value[0];
        return 0;
    }
    if(dp[i][Wt]!=-1)return dp[i][Wt];
    int notTake=getAns(weight,value,i-1,Wt,dp);
    int Take=0;
    if(Wt>=weight[i])Take=getAns(weight,value,i-1,Wt-weight[i],dp)+value[i];
    return dp[i][Wt]=max(notTake,Take);
}
int Tabulation(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    for(int i=0;i<n;i++)dp[i][0]=0;
    for(int Wt=0;Wt<=maxWeight;Wt++){
        if(weight[0]<=Wt)dp[0][Wt]=value[0];
        else dp[0][Wt]=0;
    }
    for(int i=1;i<n;i++){
        for(int Wt=0;Wt<=maxWeight;Wt++){
            int notTake=dp[i-1][Wt];
            int Take=0;
            if(Wt>=weight[i])Take=dp[i-1][Wt-weight[i]]+value[i];
            dp[i][Wt]=max(notTake,Take);
        }
    }
    return dp[n-1][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
//     vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return Tabulation(weight,value,n,maxWeight);
}