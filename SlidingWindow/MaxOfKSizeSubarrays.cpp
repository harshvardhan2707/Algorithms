#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int arr[n],ans[n-k];
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum=0;
    for(int i=0;i<k;i++)sum+=arr[i];
    ans[0]=sum;
    for(int i=1;i<=n-k;i++){
        sum-=arr[i-1];
        sum+=arr[k+i-1];
        ans[i]=sum;
    }
    // for(int i=0;i<=n-k;i++)cout<<ans[i]<<" ";
    cout<<*max_element(ans,ans+n-k);
	return 0;
}