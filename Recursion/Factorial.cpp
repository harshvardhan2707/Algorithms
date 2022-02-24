#include <bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n>1){
        return fact(n-1)*n;
    }
    return 1;
}
int fact1(int n){
    int x=n;
    n--;
    while(n-->1){
        x*=n;
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<fact(5)<<" "<<fact(5);
	return 0;
}