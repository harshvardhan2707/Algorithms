#include <bits/stdc++.h>
using namespace std;
struct Sequence{
    int Profit,deadline;
    Sequence(int Profit,int deadline){
        this->Profit=Profit;
        this->deadline=deadline;
    }
};
bool SortProfits(Sequence a,Sequence b){
    return a.Profit>b.Profit;
}
int MaxDeadline(Sequence arr[],int size){
    int value=0;
    for(int i=0;i<size;i++){
        if(arr[i].deadline>value)value=arr[i].deadline;
    }
    return value;
}
int TotalProfit(Sequence arr[],int size){
    sort(arr,arr+size,SortProfits);
    int value=MaxDeadline(arr,size),value1=value;
    int arr1[value]={0};
    for(int i=0;i<size;i++){
        if(value>0){
        for(int j=arr[i].deadline;j>0;j--){
            if(arr1[j-1]==0){
                arr1[j-1]=arr[i].Profit;value--;break;
            }}
        }
        else break;
    }
    int ans=0;
    for(int i=0;i<value1;i++)ans+=arr1[i];
    for(int i=0;i<value1;i++){
        cout<<arr1[i]<<" ";
    }
    return ans;
    
}
int main(){
    Sequence arr[]={{35,3},{30,4},{25,4},{20,2},{15,3},{12,1},{5,2}};
    cout<<TotalProfit(arr,7);
}