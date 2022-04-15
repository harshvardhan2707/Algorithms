#include <bits/stdc++.h>
using namespace std;
void PrintAllPerms(string s,int index,string &ans){
    if(index>=s.size()){
        cout<<ans<<"\n";return;
    }
    ans+=s[index];
    PrintAllPerms(s,index+1,ans);
    ans.pop_back();
    PrintAllPerms(s,index+1,ans);
}
int main(){
    string s;cin>>s;
    string ans="";
    PrintAllPerms(s,0,ans);
}