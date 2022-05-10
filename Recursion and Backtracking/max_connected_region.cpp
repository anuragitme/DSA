//Consider a matrix with rows and columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are also connected, they form a region. find the length of the largest region.

#include<bits/stdc++.h>

using namespace std;

int hs=0;

bool validblock(int i,int j,int n,int m){
    if(i<n && i>=0 && j<m && j>=0){
        return true;
    }
    return false;
}

void lcheck(vector<vector<int>> &board,int n,int m,int i,int j){
    board[i][j]=0;
    hs++;

    if(validblock(i+1,j,n,m) && board[i+1][j]==1){
        lcheck(board,n,m,i+1,j);
    }

    if(validblock(i+1,j+1,n,m) && board[i+1][j+1]==1){
        lcheck(board,n,m,i+1,j+1);
    }

    if(validblock(i+1,j-1,n,m) && board[i+1][j-1]==1){
        lcheck(board,n,m,i+1,j-1);
    }

    if(validblock(i,j-1,n,m) && board[i][j-1]==1){
        lcheck(board,n,m,i,j-1);
    }

    if(validblock(i,j+1,n,m) && board[i][j+1]==1){
        lcheck(board,n,m,i,j+1);
    }

    if(validblock(i-1,j,n,m) && board[i-1][j]==1){
        lcheck(board,n,m,i-1,j);
    }

    if(validblock(i-1,j-1,n,m) && board[i-1][j-1]==1){
        lcheck(board,n,m,i-1,j-1);
    }

    if(validblock(i-1,j+1,n,m) && board[i-1][j+1]==1){
        lcheck(board,n,m,i-1,j+1);
    }

}

int solve(vector<vector<int>> &board,int n,int m){
    int localmax=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                lcheck(board,n,m,i,j);
                int lans=hs;
                hs=0;
                localmax=max(localmax,lans);
            }
        }
    }
    return localmax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> board;
    vector<int> lol(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>lol[j];
        }
        board.push_back(lol);
    }
    cout<<solve(board,n,m)<<endl;


    return 0;
}