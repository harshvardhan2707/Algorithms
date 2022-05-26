#include <bits/stdc++.h>
using namespace std;
int getMinSum(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>& dp){
    if(i==n-1)return dp[i][j]=triangle[i][j];
    if(dp[i][j]!=0)return dp[i][j];
    int d=getMinSum(triangle,i+1,j,n,dp);
    int dg=getMinSum(triangle,i+1,j+1,n,dp);
    return dp[i][j]=min(d,dg)+triangle[i][j];
}
int Tabulate(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>& dp){
    for(int i=n-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            if(i==n-1)dp[i][j]=triangle[i][j];
            else{
                int d=dp[i+1][j];
                int dg=dp[i+1][j+1];
                dp[i][j]=min(d,dg)+triangle[i][j];
            }
        }
    }
    return dp[0][0];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n,vector<int>(n,0));
    return getMinSum(triangle,0,0,n,dp);
}
int main(){

}