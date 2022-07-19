#include <bits/stdc++.h>
using namespace std;
int mod=(int)(1e9+7);
int getAns(vector<int> &num,int i,int tar,vector<vector<int>> &dp){
    if(i==0){
        if(tar==0 && num[0]==0)return 2;
        if(num[0]==tar || tar==0)return 1;
        return 0;
    }
    if(dp[i][tar]!=-1)return dp[i][tar];
    int notTake=getAns(num,i-1,tar,dp)%mod;
    int Take=0;
    if(tar>=num[i])Take=getAns(num,i-1,tar-num[i],dp)%mod;
    return dp[i][tar]=(notTake+Take)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(auto i:arr)sum+=i;
    if(sum-d<0 || (sum-d)%2==1)return 0;
    vector<vector<int>> dp(n,vector<int>((sum-d)/2+1,-1));
    return getAns(arr,n-1,(sum-d)/2,dp);
//     return dp[n-1][(sum-d)/2];
}


