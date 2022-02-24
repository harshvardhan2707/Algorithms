#include <bits/stdc++.h>
using namespace std;
int fun(int n){
    if(n>100){
        return n-10;
    }
    return fun(fun(n+11));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<fun(95);
	return 0;
}