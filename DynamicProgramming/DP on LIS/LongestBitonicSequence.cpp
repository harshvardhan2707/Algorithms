#include <bits/stdc++.h>
using namespace std;
vector<int> FinalAns(vector<int>& arr, int n){
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[j]+1>dp[i])dp[i]=dp[j]+1;
        }
    }
    return dp;
}
int longestBitonicSequence(vector<int>& arr, int n) {
	vector<int> dp1=FinalAns(arr,n);
    reverse(arr.begin(),arr.end());
    vector<int> dp2=FinalAns(arr,n);
    int Maxi=dp1[0]+dp2[0]-1;
    for(int i=1;i<n;i++){
        Maxi=max(Maxi,dp1[i]+dp2[i]-1);
    }
    return Maxi;
} 
