#include <bits/stdc++.h>
using namespace std;
int getFinalAns(int r,int c,vector<vector<int>> &grid,int i,int j1,int j2,vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>=c || j2<0 || j2>=c)return -1e9;
    if(i==r-1){
        if(j1==j2)return dp[i][j1][j2]=grid[i][j1];
        return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int finalAns=0;
    for(int x=j1-1;x<=j1+1;x++){
        for(int y=j2-1;y<=j2+1;y++){
            finalAns=max(finalAns,getFinalAns(r,c,grid,i+1,x,y,dp));
        }
    }
    if(j1==j2)return dp[i][j1][j2]=finalAns+grid[i][j1];
    return dp[i][j1][j2]=finalAns+grid[i][j1]+grid[i][j2];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return getFinalAns(r,c,grid,0,0,c-1,dp);
}
int main(){
    
}