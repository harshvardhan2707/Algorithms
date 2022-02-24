#include <iostream>
using namespace std;
void Merge(int a[],int low,int mid,int high){
    int a1[mid-low+1],a2[high-mid],j=0,k=0,l1=0,l2=0;
    for(int i=low;i<=mid;i++){
        a1[j++]=a[i];
    }
    for(int i=mid+1;i<=high;i++){
        a2[k++]=a[i];
    }
    while(l1<j && l2<k){
        if(a1[l1]<a2[l2])a[low++]=a1[l1++];
        else a[low++]=a2[l2++];
    }
    for(;l1<j;l1++)a[low++]=a1[l1];
    for(;l2<k;l2++)a[low++]=a2[l2];
}
void MergeSort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}
void printIt(int a[],int size){
    for(int i=0;i<size;i++)cout<<a[i]<<" ";
}
int main(){
    int a[10]={6,2,4,1,8,10,2,34,12,11};
    MergeSort(a,0,9);
    printIt(a,10);
}