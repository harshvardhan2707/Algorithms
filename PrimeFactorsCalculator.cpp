#include <bits/stdc++.h>
#define vi vector<int>
#define qi queue<int>
#define PB push_back
#define pqi priority_queue<int>
using namespace std;
typedef long long ll;
void returnPrimeFactors(ll N){
    ll count=0;
    if(N%2==0){
        while(N%2==0){
            count++;N/=2;
        }
        cout<<"("<<2<<"^"<<count<<")";
    }
    for(ll i=3;i*i<=N;i+=2){
        if(N%i==0){
            count=0;
            while(N%i==0){
                count++;N/=i;
            }
            cout<<"("<<i<<"^"<<count<<")";
        }
    }
    if(N>1)cout<<"("<<N<<"^"<<1<<")";
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    returnPrimeFactors(100);
	return 0;
}