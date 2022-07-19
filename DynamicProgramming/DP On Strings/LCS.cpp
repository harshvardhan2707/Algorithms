#include <bits/stdc++.h>
using namespace std;
int getAns(string s,string t,int i,int j,vector<vector<int>> &dp){
    if(i==1||j==1)return s[i-1]==t[j-1];
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i-1]==t[j-1])return dp[i][j]=1+getAns(s,t,i-1,j-1,dp);
    else return dp[i][j]=max(getAns(s,t,i-1,j,dp),getAns(s,t,i,j-1,dp));
}
int Tabulation(string s, string t){
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
    // for(int i=0;i<=s.size();i++)if(s[i]==t[0])dp[i][0]=1;
    // for(int j=0;j<=t.size();j++)if(s[0]==t[j])dp[0][j]=1;
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[s.size()][t.size()];
}
int lcs(string s, string t)
{
//     vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
//     return getAns(s,t,s.size()-1,t.size()-1,dp);
    return Tabulation(s,t);
}