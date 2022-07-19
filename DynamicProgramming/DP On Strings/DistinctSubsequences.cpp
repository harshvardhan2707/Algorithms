#include <bits/stdc++.h>
using namespace std;
int getFinalAns(string t, string s,int i,int j,vector<vector<int>> &dp){
    if(j==-1)return 1;
    if(i==-1)return 0;
    if(dp[i][j]!=-1)return dp[i][j]%1000000007;
    if(t[i]!=s[j])return dp[i][j]=getFinalAns(t,s,i-1,j,dp)%1000000007;
    else{
        return dp[i][j]=(getFinalAns(t,s,i-1,j,dp)%1000000007+getFinalAns(t,s,i-1,j-1,dp)%1000000007)%1000000007;
    }
}
int Tabulation(string s, string t) {
    int n=s.size(),m=t.size();
    vector<vector<double>> dp(n+1,vector<double>(m+1,0));
for(int i=0;i<=n;i++)dp[i][0]=1;
for(int j=1;j<=m;j++)dp[0][j]=0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]!=t[j-1])dp[i][j]=dp[i-1][j];
        else dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]);
    }
}
return (int)dp[n][m];    }
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>> dp(lt,vector<int>(ls,-1));
    return getFinalAns(t,s,lt-1,ls-1,dp);
}
int main(){
    string t,s;cin>>t>>s;
    cout<<subsequenceCounting(t,s,t.size(),s.size());
}