#include <bits/stdc++.h>
using namespace std;
struct Knap{
    int profit,weight;
    Knap(int profit,int weight){
        this->profit=profit;
        this->weight=weight;
    }
};
bool SortRatio(Knap a,Knap b){
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}
double FindProfit(Knap arr[],int size,int MaxWeight){
    sort(arr,arr+size,SortRatio);
    int curWeight=0;
    double FinalProfit=0.0;
    for(int i=0;i<size;i++){
        if(curWeight+arr[i].weight<=MaxWeight){
            curWeight+=arr[i].weight;
            FinalProfit+=arr[i].profit;
    }
    else{
        FinalProfit+=(double)(MaxWeight-curWeight)*((double)arr[i].profit/(double)arr[i].weight);
        break;
    }
    
}return FinalProfit;
}
int main(){
    Knap arr[]={{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
    cout<<FindProfit(arr,7,15);
}