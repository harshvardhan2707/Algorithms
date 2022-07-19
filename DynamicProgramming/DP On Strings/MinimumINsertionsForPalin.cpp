#include <bits/stdc++.h>
using namespace std;
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
int minInsertion(string &str)
{
    string t=str;
    reverse(t.begin(),t.end());
    int X=Tabulation(str,t);
    return str.size()-X;
}
int main(){
    string s;
    cin>>s;
    cout<<minInsertion(s);
}