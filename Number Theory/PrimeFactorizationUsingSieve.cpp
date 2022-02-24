#include <bits/stdc++.h>
#define vi vector<int>
#define qi queue<int>
#define REP(i,n) for(ll i=0;i<n;i++)
#define PB push_back
#define pqi priority_queue<int>
using namespace std;
typedef long long ll;
int Sieve[10000001];
void RunSieve(){
    for(int i=2;i*i<=10000000;i++){
        if(Sieve[i]==0){
            int x=i*i;
            while(x<=10000000){
                if(Sieve[x]==0){
                Sieve[x]=i;}x+=i;
            }
        }
    }
}
void PrimeFactorize(int n){
    while(n>1){
        if(Sieve[n]==0){cout<<n<<" ";
        n/=n;}
        else{
            cout<<Sieve[n]<<" ";
            n/=Sieve[n];
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    RunSieve();
    int n;cin>>n;
    PrimeFactorize(n);
	return 0;
}