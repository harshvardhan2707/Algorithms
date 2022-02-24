#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>> minHeap;
        for(long long i=0;i<n;i++)minHeap.push(arr[i]);
        long long ans=0;
        while(n-->1){
            long long i=minHeap.top();minHeap.pop();
            long long j=minHeap.top();minHeap.pop();
            ans=ans+i+j;
            minHeap.push(i+j);
        }
        return ans;
    }
int main(){
    long long n;cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
}