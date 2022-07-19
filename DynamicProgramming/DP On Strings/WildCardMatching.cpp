#include <bits/stdc++.h>
using namespace std;
bool getFinalAns(string &p,string &t,int i,int j,vector<vector<int>> &dp){
//     if(i==0 && p[i]=='*')return true;
    if(i<0 && j<0)return true;
    if(i<0 && j>=0)return false;
    if(j<0){
        for(int k=0;k<=i;k++){
            if(p[k]!='*')return false;
        }
        return true;
    }
//     if(i==0 && p[i]=='*')return true;
    if(i==0 && j==0){
        return p[i]==t[j] || p[i]=='?' || p[i]=='*';
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(p[i]==t[j] || p[i]=='?')return dp[i][j]=getFinalAns(p,t,i-1,j-1,dp);
    if(p[i]=='*')return dp[i][j]=getFinalAns(p,t,i,j-1,dp)||getFinalAns(p,t,i-1,j,dp);
    return dp[i][j]=false;
    
}
bool Tabulation(string p,string t){
    int n=p.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    dp[0][0]=true;
    for(int j=1;j<=m;j++)dp[0][j]=false;
    bool Flag=true;
    for(int i=1;i<=n;i++){
        if(p[i-1]!='*')Flag=false;
        dp[i][0]=Flag;
    }
    dp[1][1]=(p[0]==t[0]||p[0]=='?'||p[0]=='*');
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1)continue;
            if(p[i-1]==t[j-1]||p[i-1]=='?')dp[i][j]=dp[i-1][j-1];
            else if(p[i-1]=='*')dp[i][j]=dp[i][j-1]||dp[i-1][j];
            else dp[i][j]=false;
        }
    }
    return dp[n][m];
}
bool wildcardMatching(string pattern, string text)
{
//     int n=pattern.size(),m=text.size();
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     return getFinalAns(pattern,text,n-1,m-1,dp);
    return Tabulation(pattern,text);
}
int main(){
    string p,t;cin>>p>>t;
    cout<<wildcardMatching(p,t);
}