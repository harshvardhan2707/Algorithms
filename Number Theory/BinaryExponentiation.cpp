#include <bits/stdc++.h>
#define vi vector<int>
#define qi queue<int>
#define PB push_back
#define pqi priority_queue<int>
using namespace std;
typedef long long ll;
ll BinaryExponentiation(ll a,ll n){
    if(n==0)return 1;
    if(n%2==0)return BinaryExponentiation(a*a,n/2);
    else return a*BinaryExponentiation(a*a,(n-1)/2);
}
ll BinaryExponentiationIterative(ll a,ll n){
    ll ans=1;
    while(n>0){
        if(n%2==0){
            a*=a;n/=2;
        }
        else{
            ans*=a;n--;
        }
    }
    return ans;
}
ll ModularExponentiationIterative(ll a,ll n,ll p){
    ll ans=1;
    while(n>0){
        if(n%2==0){
            a=(a*a)%p;n/=2;
        }
        else{
            ans=(ans*a)%p;n--;
        }
    }
    return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll a,n;
    cin>>a>>n;
    cout<<BinaryExponentiationIterative(a,n);
	return 0;
}