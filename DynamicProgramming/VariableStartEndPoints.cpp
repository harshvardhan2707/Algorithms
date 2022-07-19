#include <bits/stdc++.h>
using namespace std;
int getFinalAnswer(vector<vector<int>> &matrix,int i,int j,int n,int m,vector<vector<int>> &dp){
    if(j<0 || j>=m)return -1e8;
    if(i==0)return matrix[0][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int left=getFinalAnswer(matrix,i-1,j-1,n,m,dp);
    int center=getFinalAnswer(matrix,i-1,j,n,m,dp);
    int right=getFinalAnswer(matrix,i-1,j+1,n,m,dp);
    return dp[i][j]=max(left,max(center,right))+matrix[i][j];
}
// int Tabulation(vector<vector<int>> &matrix,int n,int m){
//     vector<vector<int>> dp(n,(vector<int>(m,0)));
//     for(int j=0;j<m;j++)dp[0][j]=matrix[0][j];
//     for(int i=1;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(j>0)int left=dp[i-1][j-1];
//             int center=dp[i-1][j];
//             if(j<m)int right=dp[i-1][j+1];
//         }
//     }
// }
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size(),m=matrix[0].size();
    vector<vector<int>> dp(n,(vector<int>(m,-1)));
    int maxVal=getFinalAnswer(matrix,n-1,0,n,m,dp);
    for(int j=1;j<m;j++){
        int X=getFinalAnswer(matrix,n-1,j,n,m,dp);
        if(maxVal<X)maxVal=X;
    }
    return maxVal;
}
// int main(){
//     int 
// }
