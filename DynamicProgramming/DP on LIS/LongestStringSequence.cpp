#include <bits/stdc++.h>
using namespace std;
bool Compare(string &s,string &t){
    if(s.size()-t.size()!=1)return false;
    int i=0,j=0;
    while(i<s.size()){
        if(s[i]==t[j]){
            i++;j++;
        }
        else i++;
    }
    return i==s.size() && j==t.size();
}
bool SortIt(string a,string b){
    return a.size()<b.size();
}
int FinalAns1(vector<string> &arr){
    int n=arr.size();
    vector<int> dp(n,1);
    int Max=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(Compare(arr[i],arr[j])){
                if(1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
            }
        }
        if(dp[i]>Max){
            Max=dp[i];
        }
    }}
    return Max;
}
int longestStrChain(vector<string> &arr)
{
    sort(arr.begin(),arr.end(),SortIt);
    return FinalAns1(arr);
}
int main(){
    int n;cin>>n;
    vector<string> X(n);
    for(int i=0;i<n;i++)cin>>X[i];
    cout<<longestStrChain(X);
}