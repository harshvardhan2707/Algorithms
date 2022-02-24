#include <bits/stdc++.h>
#define vi vector<int>
// #include <boost/multiprecision/cpp_int.hpp>
//Refer boost library is some answers have problem
#define MAX(arr,n) *max_element(arr , arr + n)
#define qi queue<int>
#define REP(x,n) for(ll i=x;i<n;i++)
#define W(t) while(t-->0)
#define PB push_back
#define pqi priority_queue<int>
using namespace std;
// using namespace boost::multiprecision;
typedef long long ll;
ll ModVal(ll i,ll n){
    if(n==1)return i%10;
    if(n%2)return ModVal(i,n-1)%10*i%10;
    return ModVal((i*i)%10,n/2)%10;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll x;cin>>x;
    if(x==0)cout<<1;
    else cout<<ModVal(8,x);
	return 0;
}