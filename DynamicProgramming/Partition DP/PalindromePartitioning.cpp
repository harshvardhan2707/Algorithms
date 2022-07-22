#include <bits/stdc++.h>
using namespace std;
bool isPalin(string s){
    int X=s.size();
    for(int i=0,j=X-1;i<j;i++,j--){
        if(s[i]!=s[j])return false;
    }
    return true;
}
int FinalAns(string &str,int i,int n,vector<int> &dp){
    if(i==n)return -1;
    if(dp[i]!=-1)return dp[i];
    int Min=1e9;
    for(int ind=i;ind<n;ind++){
        if(isPalin(str.substr(i,ind-i+1))){
            Min=min(Min,1+FinalAns(str,ind+1,n,dp));
        }
    }
    return dp[i]=Min;
}
int Tabulation(string str){
    int n=str.size();
    vector<int> dp(n+1,-1);
    for(int i=n-1;i>=0;i--){
        int Min=1e9;
        for(int ind=i;ind<n;ind++){
            if(isPalin(str.substr(i,ind-i+1))){
                Min=min(Min,1+dp[ind+1]);
            }
        }
        dp[i]=Min;
    }
    return dp[0];
}
int palindromePartitioning(string str) {
//     int n=str.size();
//     vector<int> dp(n,-1);
//     return FinalAns(str,0,str.size(),dp);
    return Tabulation(str);
}
