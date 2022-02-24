#include <bits/stdc++.h>
using namespace std;
void A(int n);
void B(int n);
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    A(20);
	return 0;
}
void A(int n){
    if(n>0){
        cout<<n<<" ";
        B(n-1);
    }
}
void B(int n){
    if(n>1){
        cout<<n<<" ";
        A(n/2);
    }
}