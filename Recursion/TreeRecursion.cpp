#include <bits/stdc++.h>
using namespace std;
void fun(int n){
    if(n>0){
        cout<<n<<" ";
        fun(n-1);
        fun(n-1);
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    fun(3);
	return 0;
}