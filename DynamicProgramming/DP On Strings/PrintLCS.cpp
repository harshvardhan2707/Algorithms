#include <bits/stdc++.h>
using namespace std;
int Tabulation(string s, string t,vector<vector<int>> &dp){
    for(int i=0;i<s.size();i++)if(s[i]==t[0])dp[i][0]=1;
    for(int j=0;j<t.size();j++)if(s[0]==t[j])dp[0][j]=1;
    for(int i=1;i<s.size();i++){
        for(int j=1;j<t.size();j++){
            if(s[i]==t[j])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[s.size()-1][t.size()-1];
}
int lcs(string s, string t)
{
    vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
//     return getAns(s,t,s.size()-1,t.size()-1,dp);
    int F=Tabulation(s,t,dp);
    stack<char> X;
    int n=s.size()-1,m=t.size()-1;
    while(n>0 && m>0){
        if(s[n]==t[m]){
            X.push(s[n]);n--;m--;
        }
        else if(dp[n][m]==dp[n-1][m])n--;
        else m--;
    }
    if(dp[n][m]!=0){
        if(n==0)X.push(s[n]);
        else X.push(t[m]);
    }
    while(!X.empty()){
        cout<<X.top();X.pop();
    }
    return F;
}