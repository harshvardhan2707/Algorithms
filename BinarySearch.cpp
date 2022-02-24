#include <iostream>
using namespace std;
int BinarySearchIter(int arr[],int size,int value){
    int l=0,h=size-1,mid;
    while(l<h){
        mid=(l+h)/2;
        if(arr[mid]==value) return mid;
        else if(arr[mid]>value) h=mid-1;
        else if(arr[mid]<value) l=mid+1;
    }
    return -1;
}
int BinarySearchRec(int arr[],int low,int high,int value){
    if(low==high){
        if(arr[low]==value) return low;
        return -1;
    }
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==value) return mid;
    if(arr[mid]>value) return BinarySearchRec(arr,low,mid-1,value);
    return BinarySearchRec(arr,mid+1,high,value);

}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    cout<<BinarySearchRec(arr,0,9,4);
}