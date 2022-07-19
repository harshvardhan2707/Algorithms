#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &arr)
{
    int n=arr.size();
    int maxi=1;
    vector<int> dp(n,1),cut(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                cut[i]=cut[j];
            }
            else if(arr[i]>arr[j] && dp[j]+1==dp[i])cut[i]+=cut[j];
        }
        maxi=max(maxi,dp[i]);
    }
    int nos=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi)nos+=cut[i];
    }
    return nos;
}