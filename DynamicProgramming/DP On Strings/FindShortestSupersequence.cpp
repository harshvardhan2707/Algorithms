#include <bits/stdc++.h>
using namespace std;
string shortestSupersequence(string s, string t)
{
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
    // for(int i=0;i<=s.size();i++)if(s[i]==t[0])dp[i][0]=1;
    // for(int j=0;j<=t.size();j++)if(s[0]==t[j])dp[0][j]=1;
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int n=s.size(),m=t.size();
    while(n>0 && m>0){
        if(s[n-1]==t[m-1]){
            ans+=s[n-1];n--;m--;
        }
        else if(dp[n-1][m]>dp[n][m-1]){
            ans+=s[n-1];
            n--;
        }
        else{
            ans+=t[m-1];
            m--;
        }
    }
    while(n>0){
        ans+=s[n-1];
        n--;
    }
    while(m>0){
        ans+=t[m-1];
        m--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s,t;cin>>s>>t;
    cout<<shortestSupersequence(s,t);
}