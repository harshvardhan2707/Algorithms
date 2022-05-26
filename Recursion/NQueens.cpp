#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int col,int row,vector<string> &board,int n){
        int dupCol=col--,dupRow=row--;
        while(col>=0 && row>=0){
            if(board[row--][col--]=='Q')return false;
        }
        col=dupCol;row=dupRow;
        col--;
        while(col>=0){
            if(board[row][col--]=='Q')return false;
        }
        col=--dupCol;row=++dupRow;
        while(col>=0 && row<n){if(board[row++][col--]=='Q')return false;}
        return true;
    }
    void getAllPossibleBoards(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(col,row,board,n)){
                board[row][col]='Q';
                getAllPossibleBoards(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string X(n,'.');
        for(int i=0;i<n;i++)board[i]=X;
        getAllPossibleBoards(0,board,ans,n);
        return ans;
    }
};
int main(){
    Solution x;int n;cin>>n;
    vector<vector<string>> ans=x.solveNQueens(n);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<"\n";
        }
        cout<<"------------------------\n\n";
    }
    return 0;
}