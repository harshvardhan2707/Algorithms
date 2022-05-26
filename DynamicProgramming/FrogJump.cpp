#include <bits/stdc++.h>
using namespace std;
int getMins(int n,vector<int> &heights,int arr[]){
	if(n<=1)return 0;
	if(n==2)return arr[1]=abs(heights[1]-heights[0]);
	if(arr[n-1]!=0)return arr[n-1];
	return arr[n-1]=min(abs(heights[n-1]-heights[n-2])+abs(getMins(n-1,heights,arr)),abs(heights[n-1]-heights[n-3])+abs(getMins(n-2,heights,arr)));
}
int Tabulation(int n,vector<int> &heights){
if(n==1)return 0;
    int arr[n]={0};
	arr[1]=abs(heights[1]-heights[0]);
	for(int i=2;i<n;i++){
		int minusOne=abs(heights[i]-heights[i-1])+arr[i-1];
		int minusTwo=abs(heights[i]-heights[i-2])+arr[i-2];
		arr[i]=min(minusOne,minusTwo);
	}
    return arr[n-1];
}
int SpaceOptimize(int n,vector<int> &heights){
	if(n==1)return 0;
	if(n==2)return abs(heights[1]-heights[0]);
    int l=0,r=0,fAns=0;
	for(int i=1;i<n;i++){
		int X=abs(heights[i]-heights[i-1])+l;
		int Y=1e9;
		if(i>1)Y=abs(heights[i]-heights[i-2])+r;
		int fAns=min(X,Y);
		r=l;
		l=fAns;
	}
	return l;
}
int frogJump(int n, vector<int> &heights)
{
    int arr[n]={0};
	return getMins(n,heights,arr);
}
int main(){
    vector<int> heights{10,40,23,14};
    cout<<frogJump(4,heights);
}