#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b){
    if(b==0)return a;
    if(a<b){
        a+=b;
        b=a-b;
        a=a-b;
    }
    return GCD(b,a%b);
}
int main(){
    cout<<GCD(12,125);
}