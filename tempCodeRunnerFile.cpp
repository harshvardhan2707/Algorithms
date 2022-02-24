#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M,X;
cin>>N>>M;
int a[N];
for(int i=0;i<N;i++)cin>>a[i];
for (int i=0;i<M;i++){
cin>>X;
for(int j;j<N;j++){
if(X-a[j]<=0){
cout<<j+1<<" "<<X<<"\n";break;}
X-=a[j];
}
}
return 0;
}