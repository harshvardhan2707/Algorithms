#include <bits/stdc++.h>
using namespace std;
int getMinPath(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
    if(i==0 && j==0)return dp[i][j]=grid[i][j];
    if(i<0 || j<0)return 1e9;
    if(dp[i][j]==0)return dp[i][j]=min(getMinPath(grid,i-1,j,dp),getMinPath(grid,i,j-1,dp))+grid[i][j];
    return dp[i][j];
}
int minSumPath(vector<vector<int>> &grid) {
    int i=grid.size(),j=grid[0].size();
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
    return getMinPath(grid,i-1,j-1,dp);
}
int main(){
    
}