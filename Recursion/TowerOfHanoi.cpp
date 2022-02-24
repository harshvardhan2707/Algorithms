#include <iostream>
using namespace std;
void TowerOfHanoi(int n,char A,char B,char C){
    if(n>0){
    TowerOfHanoi(n-1,A,C,B);
    cout<<"Move a disc from "<<A<<" to "<<C<<"\n";
    TowerOfHanoi(n-1,B,A,C);
    }
}
int main(){
    TowerOfHanoi(1,'A','B','C');
}