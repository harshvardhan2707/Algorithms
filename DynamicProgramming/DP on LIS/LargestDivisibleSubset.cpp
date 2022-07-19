#include <bits/stdc++.h>
using namespace std;
vector<int> FinalAns1(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,1);
    vector<int> Order(n,0);
    int Max=1;
    int Ind=0;
    for(int i=0;i<n;i++)Order[i]=i;
    for(int i=0;i<n;i++){
//         int Max=1;
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0){
                if(1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
                Order[i]=j;
            }
        }
        if(dp[i]>Max){
            Max=dp[i];
            Ind=i;
        }
    }}

//     for(int i=1;i<n;i++){
//         if(dp[i]>=Max){
//             Max=dp[i];
//             Ind=i;
//         }
//     }
        vector<int> FinalAns;
    FinalAns.push_back(arr[Ind]);
    while(Order[Ind]!=Ind){
        Ind=Order[Ind];
        FinalAns.push_back(arr[Ind]);
//         cout<<arr[Ind]<<" ";
        
    }
//         FinalAns.push_back(arr[Ind]);
//     cout<<arr[Ind];
    return FinalAns;
}
vector<int> divisibleSet(vector<int> &arr){
    sort(arr.begin(),arr.end());
    return FinalAns1(arr);
}
int main(){
    
}