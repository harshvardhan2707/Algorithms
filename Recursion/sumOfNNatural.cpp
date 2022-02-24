#include <bits/stdc++.h>
using namespace std;
int sumOfNNatural(int n){
    if(n>0){
        return sumOfNNatural(n-1)+n;
    }
    return 0;
}
int iSum(int n){
    int s=0;
    for(int i=1;i<=n;i++){
        s+=i;
    }
    return s;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<sumOfNNatural(10)<<"\n"<<iSum(10);
	return 0;
}