#include <bits/stdc++.h>
using namespace std;
int returnList(int arr[],int size){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<size;i++)minHeap.push(arr[i]);
    int ans=0;
    while(size-->1){
        int i=minHeap.top();minHeap.pop();
        int j=minHeap.top();minHeap.pop();
        ans+=i+j;
        minHeap.push(i+j);
            }
            return ans;
}
int main(){
    int x;cin>>x;
    int arr[x];
    for(int i=0;i<x;i++)cin>>arr[i];
    cout<<returnList(arr,x);
}