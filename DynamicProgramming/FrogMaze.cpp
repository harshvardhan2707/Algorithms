#include <bits/stdc++.h>
using namespace std;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n,vector<int>(m,0));
    int mod=1e9+7;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)dp[i][j]=1;
            else{
                int up=0,right=0;
                if(i>0 && mat[i][j]!=-1)up=dp[i-1][j]%mod;
                if(j>0 && mat[i][j]!=-1)right=dp[i][j-1]%mod;
                dp[i][j]=(up+right)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
int main(){
    int t;cin>>t;
    while(t-->0){
        int n,m;cin>>n>>m;
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cin>>mat[i][j];
        }
        cout<<mazeObstacles(n,m,mat);
    }
}