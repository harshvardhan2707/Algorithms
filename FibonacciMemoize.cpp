#include <bits/stdc++.h>
#define vi vector<int>
#define MAX(arr,n) *max_element(arr , arr + n)
#define qi queue<int>
#define REP(x,n) for(ll i=x;i<n;i++)
#define W(t) while(t-->0)
#define PB push_back
#define pqi priority_queue<int>
using namespace std;
typedef long long ll;
int fib[10000]={0};
//multiply power and solve are great algorithms for faster calculation of factorials especially if their first and second elements are not 0 and 1 check it out once future Harsh
void multiply(long long I[][2],long long arr[][2]){
    long long x[2][2];
    long long mod=1000000007;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            x[i][j]=0;
            for(int k=0;k<2;k++){
                x[i][j]=(x[i][j]%mod+((I[i][k]%mod)*(arr[k][j]%mod))%mod)%mod;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            I[i][j]=x[i][j];
        }
    }
}
void power(long long I[][2],long long arr[][2],int pow){
    while(pow){
        if(pow%2==0){
            multiply(arr,arr);
            pow/=2;
        }
        else{
            multiply(I,arr);pow--;
        }
    }
}
int solve(int a, int b, int n) {
    if(n==1)return b;
    if(n==0) return a;
    long long mod=1000000007;
    long long arr[2][2]={{0,1},{1,1}},I[2][2]={{1,0},{0,1}};
    power(I,arr,n-1);
    return int((((I[1][0]%mod)*(a%mod))%mod+((I[1][1]%mod)*(b%mod))%mod)%mod);
}
int calcFib(int N){
    if(N==0){
        return fib[N];
    }
    if(N==1){
        fib[N]=1;return fib[N];
    }
    calcFib(N-1);
    if(fib[N]!=0)return fib[N];
    fib[N]=calcFib(N-1)+calcFib(N-2);
    return fib[N];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout<<calcFib(10);
    // cout<<fib[10];
	return 0;
}