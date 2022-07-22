#include <bits/stdc++.h>
using namespace std;
int findMax(vector<int> &num,int i,int j){
    int Max=num[i];
    for(int x=i;x<=j;x++){
        if(num[x]>Max)Max=num[x];
    }
    return Max;
}
int finalAns(vector<int> &num,int i,int n,int k,vector<int> &dp){
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int Max=-1e9;
    for(int ind=i;ind<min(i+k,n);ind++){
        Max=max(Max,findMax(num,i,ind)*(ind-i+1)+finalAns(num,ind+1,n,k,dp));
    }
    return dp[i]=Max;
}
int Tabulation(vector<int> &num,int k){
        int n=num.size();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int Max=-1e9;
        for(int ind=i;ind<min(i+k,n);ind++){
            Max=max(Max,findMax(num,i,ind)*(ind-i+1)+finalAns(num,ind+1,n,k,dp));
        }
        dp[i]=Max;
    }
    return dp[0];
}
int maximumSubarray(vector<int> &num, int k)
{
//     int n=num.size();
//     vector<int> dp(n,-1);
//     return finalAns(num,0,n,k,dp);
    return Tabulation(num,k);
}