#include <iostream>
using namespace std;
void Swap(int a[],int i,int j){
    int x=a[i];
    a[i]=a[j];
    a[j]=x;
}
int Partition(int a[],int l,int h){
    int pivot=a[l],i=l,j=h;
    while(i<j){
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j){
            Swap(a,i,j);
        }}
        Swap(a,l,j);
        return j;

}
void QuickSort(int a[],int l,int h){
    if(l<h){
        int j=Partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    a[n]=INT_FAST32_MAX;
    QuickSort(a,0,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";

}