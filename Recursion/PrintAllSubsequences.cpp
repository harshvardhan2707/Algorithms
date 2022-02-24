#include <bits/stdc++.h>
using namespace std;
void printAllSubsequences(int arr[],int n,vector<int> &l,int j){
    if(j>=n){
        for(int i=0;i<l.size();i++)cout<<l[i]<<" ";
        cout<<"\n";return;
    }
    l.push_back(arr[j]);
    printAllSubsequences(arr,n,l,j+1);
    l.pop_back();
    printAllSubsequences(arr,n,l,j+1);
}
int main(){
    int arr[]={3,1,2};
    vector<int> l;
    printAllSubsequences(arr,3,l,0);
    return 0;
}