#include <bits/stdc++.h>
using namespace std;
int countSquares(int n, int m, vector<vector<int>> &arr) {
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]==1)arr[i][j]=min(arr[i-1][j-1],min(arr[i][j-1],arr[i-1][j]))+1;
        }
    }
    int sum=0;
    for(auto i:arr){
        for(auto j:i)sum+=j;
    }
    return sum;
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>arr[i][j];
    }
    cout<<countSquares(n,m,arr);
}

