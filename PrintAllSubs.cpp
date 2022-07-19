#include <bits/stdc++.h>
using namespace std;
void printIt(string x,int i,int n,string ans){
    if(i==n){cout<<ans<<"\n";return;}
    printIt(x,i+1,n,ans+x[i]);
    printIt(x,i+1,n,ans);
}
int main(){
    string x="ABC";
    printIt(x,0,3,"");

}