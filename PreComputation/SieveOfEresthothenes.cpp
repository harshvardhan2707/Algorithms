#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Prime[1000001];
void sieve(){
	int maxN=100000;
	for(int i=2;i<=maxN;i++)Prime[i]=1;
	Prime[0]=Prime[1]=0;
	for(int i=2;i*i<=maxN;i++){
		if(Prime[i]==1){
			int l=i*i;
			while(l<=maxN){
				Prime[l]=0;
				l+=i;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	sieve();
	for(int i=0;i<100;i++)cout<<Prime[i]<<" "<<i<<"\n";
	return 0;
}