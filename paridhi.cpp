#include <iostream>
using namespace std;
void bubbleSort(string arr[],int size){
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(arr[j].compare(arr[j+1])>0){
                string x=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=x;
            }
        }
    }
}
int main(){
    int n;cin>>n;
    if(n<=0)cout<<"Invalid input found, the program will now terminate";
    else{
    string arr[n];
    cin.ignore(256,'\n');
    for(int i=0;i<n;i++)getline(cin,arr[i]);
    cout<<"Original word list\n";
    for(int i=0;i<n;i++){
        cout<<"Word "<<i+1<<" = "<<arr[i]<<"\n";
    }
    cout<<"\nWord list after sorting\n";
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<"Word "<<i+1<<" = "<<arr[i]<<"\n";}
    }
}