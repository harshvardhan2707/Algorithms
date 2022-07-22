#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;
long long FinalAns(string &exp,int i,int j,bool isTrue,vector<vector<vector<ll>>> &dp){
    if(i>j)return 0;
    if(i==j){
        if(isTrue)return exp[i]=='T';
        return exp[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue]; 
    int ways=0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        ll RightTrue=FinalAns(exp,ind+1,j,1,dp)%mod;
        ll RightFalse=FinalAns(exp,ind+1,j,0,dp)%mod;
        ll LeftTrue=FinalAns(exp,i,ind-1,1,dp)%mod;
        ll LeftFalse=FinalAns(exp,i,ind-1,0,dp)%mod;
        if(exp[ind]=='&'){
            if(isTrue)ways=(ways+LeftTrue*RightTrue%mod)%mod;
            else ways=(ways+LeftFalse*RightFalse%mod +LeftFalse*RightTrue%mod+LeftTrue*RightFalse%mod)%mod;
        }
        else if(exp[ind]=='|'){
            if(isTrue)ways=(ways+LeftTrue*RightTrue%mod+LeftTrue*RightFalse%mod+LeftFalse*RightTrue%mod)%mod;
            else ways=(ways+LeftFalse*RightFalse%mod)%mod;
        }
        else {
            if(isTrue)ways=(ways+LeftTrue*RightFalse%mod+LeftFalse*RightTrue%mod)%mod;
            else ways=(ways+LeftTrue*RightTrue%mod+LeftFalse*RightFalse%mod)%mod;
        }
    }
    return dp[i][j][isTrue]=ways%mod;
}
long long Tabulation(string &exp){
    int n=exp.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,0)));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j][1]=exp[i]=='T';
                dp[i][j][0]=exp[i]=='F';
                continue;
            }
         
            ll waysT=0,waysF=0;
            for(int ind=i+1;ind<j;ind+=2){
                ll RT=dp[ind+1][j][1]%mod;
                ll RF=dp[ind+1][j][0]%mod;
                ll LT=dp[i][ind-1][1]%mod;
                ll LF=dp[i][ind-1][0]%mod;
                    if(exp[ind]=='&'){
                        waysT=(waysT+LT*RT%mod)%mod;
                        waysF=(waysF+LF*RF%mod +LF*RT%mod+LT*RF%mod)%mod;
                        }
                    else if(exp[ind]=='|'){
            waysT=(waysT+LT*RT%mod+LT*RF%mod+LF*RT%mod)%mod;
            waysF=(waysF+LF*RF%mod)%mod;
        }
        else {
            waysT=(waysT+LT*RF%mod+LF*RT%mod)%mod;
            waysF=(waysF+LT*RT%mod+LF*RF%mod)%mod;
        }
            }
                dp[i][j][1]=waysT%mod;
                dp[i][j][0]=waysF%mod;
        }
    }
    return dp[0][n-1][1];
}
int evaluateExp(string & exp) {
//     int n=exp.size();
//     vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
//     return FinalAns(exp,0,exp.size()-1,1,dp);
    return Tabulation(exp);
}