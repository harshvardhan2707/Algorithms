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
void Print1ToN(int n){
    if(n==0)return;
    Print1ToN(n-1);
    cout<<n<<" ";

}
void PrintNTo1(int n){
    if(n==0)return;
    cout<<n<<" ";
    PrintNTo1(n-1);

}
int sum(int n){
    if(n==1)return 1;
    n+=sum(n-1);
    return n;
}
void swap(int &a,int &b){
    int temp=a;
    a=b;b=temp;
}
void reverseArray(int arr[],int n){
    static int i=0;
    if(i>=n)return;
    swap(arr[i],arr[n-1]);
    i++;
    reverseArray(arr,n-1);

}
bool isPalindrome(string &s){
    static int i=0,j=s.length();
    if(i>=j)return true;
    if(s[i]==s[j-1]){
        i++;j--;
        return isPalindrome(s);
    }
    return false;

}
void Perms(char arr[],int l,int h){
    if(l==h)cout<<arr<<"\n";
    else{
    for(int i=l;i<=h;i++){
        swap(arr[i],arr[l]);
        Perms(arr,l+1,h);
        swap(arr[i],arr[l]);
    }}
}
void PrintAllSubsequences(int arr[],int a[],int n,int tot){
    if(tot==0)return;
    for(int i=0;i<n;i++){
        if(a[i]==1)cout<<arr[i]<<" ";
    }
    cout<<"\n";
    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i]==0 && flag){
            a[i]=1;break;
    }
    else if(a[i]==1){ 
        a[i]=0;
        if(flag){
        flag=false;
    }}
    else if(a[i]==0 && !flag){
        a[i]=1;break;
    }
    }
    PrintAllSubsequences(arr,a,n,tot-1);

    
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    Print1ToN(10);cout<<"\n";
    PrintNTo1(10);cout<<"\n";
    cout<<sum(10);cout<<"\n";
    int arr[]={1,2,3,4,5};
    // reverseArray(arr,3);cout<<"\n";
    // for(int i=0;i<3;i++)cout<<arr[i]<<" ";
    // string s;cin>>s;
    // cout<<isPalindrome(s);
    int a[5]={0};
    PrintAllSubsequences(arr,a,5,(int)pow(2,5));
    // char s[]="ABCD";
    // Perms(s,0,3);
	return 0;
}