#include <bits/stdc++.h>
#define vi vector<int>
#define qi queue<int>
#define PB push_back
#define pqi priority_queue<int>
using namespace std;
typedef long long ll;
bool Sieve[1000001];bool PrimePrime[1000001];int pp[1000001]={0};
void SieveofE(){
	Sieve[0]=Sieve[1]=true;
	for(ll i=2;i*i<=1000000;i++){
		ll x=i*i;
		if(!Sieve[i]){
			while(x<=1000000){
				Sieve[x]=true;x+=i;
			}
		}
	}
}
void findPrimePrime(){
	ll x=0;
	for(ll i=0;i<=1000000;i++){
		if(!Sieve[i])x++;
		if(!Sieve[x])PrimePrime[i]=true;
	}
}
void numOfPrimePrime(){
	ll x=0;
	for(ll i=0;i<=1000000;i++){
		pp[i]=x;
		if(PrimePrime[i])x++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	SieveofE();findPrimePrime();numOfPrimePrime();
	ll t,l,r;cin>>t;
	while(t-->0){
		cin>>l>>r;
		ll x=0;
		if(PrimePrime[r])x++;
		x=x+pp[r]-pp[l];
		cout<<x<<"\n";
	}
	// for(ll i=0;i<100;i++)cout<<pp[i]<<"\n";
	return 0;
}