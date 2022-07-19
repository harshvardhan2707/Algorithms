#include <bits/stdc++.h>
#define vi vector<int>
#define Mod (long long)1e9+7
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
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t,n,k;cin>>t;
    W(t){
        cin>>n>>k;
        if(n>=k)cout<<k;
        else{
            ll X=k/n;
            ll sum=0;
                while(X==1 && n>1){
                    sum++;--k;--n;
                    X=k/n;
                }
            X=k/n;
            ll F=(ll)pow(2,29),m=29;
            while(X/F==0 && F>0){
                F/=2;
                m--;
            }
            F*=2;
            F-=1;m++;
            
            while(n>1){
                while(X>0 && (ll)(F/X)==1 && n>1){
                    sum+=m;
                    k-=F;n--;
                    X=k/n;
                }
                F/=2;m--;
            }
            F=1;
            while(F<=k){
                if(F&k)sum++;
                F*=2;
            }
            cout<<sum;
        }
        cout<<"\n";
    }
	return 0;
}