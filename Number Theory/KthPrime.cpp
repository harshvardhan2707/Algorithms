#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool arr[90000001]={0};
vector<int> l;
void Sieve(){
    arr[0]={1};arr[1]={1};
    for(ll i=2;i*i<=90000000;i++){
        if(!arr[i]){
            int j=i*i;
            while(j<=90000000){
                arr[j]=1;
                j+=i;
            }
        }
    }
    l.push_back(2);
    for(ll i=3;i<=90000000;i+=2){
        if(!arr[i])l.push_back(i);
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    Sieve();
    ll t,n;cin>>t;
    while(t-->0){
        cin>>n;
        cout<<l[n-1]<<"\n";
    }
	return 0;
}