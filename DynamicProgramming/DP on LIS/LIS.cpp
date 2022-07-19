#include <bits/stdc++.h>
using namespace std;
int FinalAns(int arr[],int i,int n,int prevMaxIndex,vector<vector<int>> &dp){
    if(i==n)return 0;
    int Select=0;
    if(dp[i][prevMaxIndex+1]!=-1)return dp[i][prevMaxIndex+1];
    if(prevMaxIndex==-1 || arr[i]>arr[prevMaxIndex])Select=FinalAns(arr,i+1,n,i,dp)+1;
    int NotSelect=FinalAns(arr,i+1,n,prevMaxIndex,dp);
    return dp[i][prevMaxIndex+1]=max(Select,NotSelect);
}
int Tabulation(int arr[],int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int prevInd=i-1;prevInd>=-1;prevInd--){
            int Select=0;
            if(prevInd==-1||arr[i]>arr[prevInd])Select=dp[i+1][i+1]+1;
            int NotSelect=dp[i+1][prevInd+1];
            dp[i][prevInd+1]=max(Select,NotSelect);
        }
    }
    return dp[0][0];
}
int SpaceOptimization(int arr[],int n){
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int i=n-1;i>=0;i--){
        for(int prevInd=i-1;prevInd>=-1;prevInd--){
            int Select=0;
            if(prevInd==-1||arr[i]>arr[prevInd])Select=prev[i+1]+1;
            int NotSelect=prev[prevInd+1];
            curr[prevInd+1]=max(Select,NotSelect);
        }
        prev=curr;
    }
    return curr[0];
    
}
int ActualFunda(int arr[],int n){
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        int Max=0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp[j]>Max)Max=dp[j];
        }
        dp[i]=dp[i]+Max;
    }
    int Max=1;
    for(int i=1;i<n;i++){
        Max=max(dp[i],Max);
    }
    return Max;
}
int PrintLIS(int arr[],int n){
    vector<int> dp(n,1);
    vector<int> Order(n,0);
    for(int i=0;i<n;i++)Order[i]=i;
    for(int i=1;i<n;i++){
        int Max=0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp[j]>Max){
                Max=dp[j];
                Order[i]=j;
            }
        }
        dp[i]=dp[i]+Max;
    }
    int Max=1;
    int Ind=0;
    for(int i=1;i<n;i++){
        if(dp[i]>Max){
            Max=dp[i];
            Ind=i;
        }
    }
    while(Order[Ind]!=Ind){
        cout<<arr[Ind]<<" ";
        Ind=Order[Ind];
    }
    cout<<arr[Ind];
    return Max;
}
int BinSearch(int arr[],int n){
    vector<int> temp;
    int len=1;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else {
            int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
    }
    return len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
//     vector<vector<int>> dp(n,vector<int>(n+1,-1));
//     return FinalAns(arr,0,n,-1,dp);
//     return Tabulation(arr,n);
//     return SpaceOptimization(arr,n);
    // return ActualFunda(arr,n);
    return BinSearch(arr,n);
}
int main(){
    int n;cin>>n;
    int  arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int X=PrintLIS(arr,n);
}