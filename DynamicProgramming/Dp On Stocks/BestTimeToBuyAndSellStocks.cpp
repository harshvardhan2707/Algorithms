#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int n=prices.size();
    int Ans=0;
    int minTillNow=prices[0];
    for(auto i:prices){
        if(i<minTillNow)minTillNow=i;
        if(i-minTillNow>Ans)Ans=i-minTillNow;
    }
    return Ans;
}
int main(){
    int size;cin>>size;
    vector<int> prices;
    for(int i=0;i<size;i++)cin>>prices[i];
    cout<<maximumProfit(prices);
}