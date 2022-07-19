#include <bits/stdc++.h>
using namespace std;
int Tabulation(string &s, string &t){
    vector<vector<int>> dp(s.size(),vector<int>(t.size(),0));
    int ans=0;
    for(int i=0;i<s.size();i++){if(s[i]==t[0]){dp[i][0]=1;ans=1;}}
    for(int j=0;j<t.size();j++){if(s[0]==t[j]){dp[0][j]=1;ans=1;}}
    
    for(int i=1;i<s.size();i++){
        for(int j=1;j<t.size();j++){
            if(s[i]==t[j]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(dp[i][j],ans);
            }
            else dp[i][j]=0;
        }
    }
    return ans;
}
int lcs(string &str1, string &str2){
    return Tabulation(str1,str2);
}