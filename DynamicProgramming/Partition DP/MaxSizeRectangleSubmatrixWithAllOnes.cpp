#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<int> X;
    int n=heights.size();
    int Max=0;
    for(int i=0;i<=n;i++){
        while(!X.empty() && (i==n||heights[X.top()]>=heights[i])){
            int height=heights[X.top()];
            X.pop();
            int width;
            if(X.empty())width=i;
            else width=i-X.top()-1;
            Max=max(Max,height*width);
        }
        X.push(i);
    }
    return Max;

}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    int FinalAns=largestRectangleArea(mat[0]);
	for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]!=0)mat[i][j]=mat[i-1][j]+1;
        }
        FinalAns=max(FinalAns,largestRectangleArea(mat[i]));
    }
    return FinalAns;
}