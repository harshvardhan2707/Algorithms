#include <iostream>
using namespace std;
void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
            arr[j+1]=key;
        }
    }
}
void insertionSortDescending(int arr[], int size)
{
for (int step = 1; step < size; step++)
{
int key = arr[step];
int j = step - 1;
while (key > arr[j] && j >= 0)
{
// For ascending order, change key> arr[j] to key< arr[j].
arr[j + 1] = arr[j];
--j;
}
arr[j + 1] = key;
}}

int main(){
    int arr[2],len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<2;i++){
        cin>>arr[i];
    }
    // insertionSort(arr,len);
    // for(int i=0;i<10;i++){
    //     cout<<arr[i]<<" ";
    // }
    cout<<"\n";
    insertionSortDescending(arr,len);
    for(int i=0;i<2;i++){
        cout<<arr[i]<<" ";
    }

}