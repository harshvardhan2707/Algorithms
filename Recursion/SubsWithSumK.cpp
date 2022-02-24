#include <bits/stdc++.h>
using namespace std;
int sumKCount(int arr[],int n,int k,int &sum,int j){
    if(j>=n){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    sum+=arr[j];
    int ans1=sumKCount(arr,n,k,sum,j+1);
    sum-=arr[j];
    int ans2=sumKCount(arr,n,k,sum,j+1);
    return ans1+ans2;
    }
bool sumKOnlyOnce(int arr[],int n,int k,int &sum,vector<int> &x,int j){
    if(j>=n){
        //Condition satisfied
        if(sum==k){
            for(auto i:x)cout<<i<<" ";
            return true;
        }
        //Condition not satisfied
        return false;
    }
    //Pick value
    sum+=arr[j];
    x.push_back(arr[j]);
    bool first=sumKOnlyOnce(arr,n,k,sum,x,j+1);
    //If one subsequence has been printed return true
    if(first)return true;
    //Don't pick value
    sum-=x[x.size()-1];
    x.pop_back();
    bool sec=sumKOnlyOnce(arr,n,k,sum,x,j+1);
    //If one subsequence has been printed return true
    if(sec)return true;
    return false;
    }
void sumK(int arr[],int n,int k,int &sum,vector<int> &x,int j){
    if(j>=n){
        if(sum==k){
            for(auto i:x)cout<<i<<" ";
            cout<<"\n";
        }
        return;
    }
    sum+=arr[j];
    x.push_back(arr[j]);
    sumK(arr,n,k,sum,x,j+1);
    sum-=x[x.size()-1];
    x.pop_back();
    sumK(arr,n,k,sum,x,j+1);
    }
int main(){
    int arr[]={2,2,-1,1};
    int sum=0;
    vector<int> x;
    // sumKOnlyOnce(arr,4,2,sum,x,0);
    cout<<sumKCount(arr,4,2,sum,0);
}