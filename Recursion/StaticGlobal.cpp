#include <bits/stdc++.h>
using namespace std;
int y=0;
int fun(int n){
    static int x=0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    cout<<"x is"<<x<<" \n";
    return 0;
}
int fun1(int n){
    y=0;
    if(n>0){
        y++;
        return fun1(n-1)+y;
    }
    return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<fun(5)<<"\n";
    cout<<fun(6)<<"\n";
	return 0;
}