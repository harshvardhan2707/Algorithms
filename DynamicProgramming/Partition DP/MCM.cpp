#include <bits/stdc++.h>
using namespace std;
int FinalAns(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i==j)return dp[i][j]=0;
    int steps=1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k=i;k<j;k++){
        steps=min(steps,FinalAns(arr,i,k,dp)+FinalAns(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j]=steps;
}
int Tabulation(vector<int> &arr, int N){
    vector<vector<int>> dp(N,vector<int>(N,0));
    int steps;
    for(int i=N-1;i>0;i--){
        for(int j=i+1;j<N;j++){
            steps=1e9;
            for(int k=i;k<j;k++){
                steps=min(steps,dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
            }
            dp[i][j]=steps;
        }
    }
    return dp[1][N-1];
}
int matrixMultiplication(vector<int> &arr, int N)
{
//     vector<vector<int>> dp(N,vector<int>(N,-1));
//     return FinalAns(arr,1,N-1,dp);
    return Tabulation(arr,N);
}