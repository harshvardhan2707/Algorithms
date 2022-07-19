#include <bits/stdc++.h>
using namespace std;
int finalAns(string &str1,string &str2,int i,int j,vector<vector<int>> &dp){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i]==str2[j])return dp[i][j]=finalAns(str1,str2,i-1,j-1,dp);
    else{
        int Replace=finalAns(str1,str2,i-1,j-1,dp);
        int Delete=finalAns(str1,str2,i-1,j,dp);
        int Insert=finalAns(str1,str2,i,j-1,dp);
        return dp[i][j]=1+min(min(Replace,Delete),Insert);
    }
}
int Tabulation(string str1,string str2){
    int n=str1.size(),m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++)dp[i][0]=i;
    for(int j=0;j<=m;j++)dp[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1];
            else{
                int Replace=dp[i-1][j-1];
                int Delete=dp[i-1][j];
                int Insert=dp[i][j-1];
                dp[i][j]=1+min(min(Replace,Delete),Insert);
            }
        }
    }
    return dp[n][m];
}
int editDistance(string str1, string str2)
{
//     vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),-1));
//     return finalAns(str1,str2,str1.size()-1,str2.size()-1,dp);
    return Tabulation(str1,str2);
}
int main(){
    string str1,str2;
    cin>>str1>>str2;
    cout<<editDistance(str1,str2);
}