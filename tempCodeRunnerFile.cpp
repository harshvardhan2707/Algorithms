

#include <bits/stdc++.h>
using namespace std;
int minCost(vector<vector<int>> &A) {
  int m=A.size(),n=A[0].size();
  for (int i=1 ; i<m ; i++){
    A[i][0] += A[i-1][0];
  }
  for (int j=1 ; j<n ; j++){
    A[0][j] += A[0][j-1];
  }
  for (int i=1 ; i<m ; i++) {
    for (int j=1 ; j<n ; j++) {
      A[i][j] += min(A[i-1][j-1], min(A[i-1][j], A[i][j-1]));
    }
  }
  return A[m-1][n-1];
}
int main() {

  vector<vector<int> > A{{5,9,6},
                      {11,5,2}};
  
  cout<<minCost(A);
}









