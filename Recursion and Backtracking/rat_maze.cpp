#include<bits/stdc++.h>

using namespace std;

// O(2^(n^2))

int x[4]={1,-1,0,0},y[4]={0,0,1,-1};
string movez="DURL";

bool isValid(int i,int j, int n,vector<vector<int>> &m){
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }
    if(m[i][j]==0){
        return false;
    }
    return true;
}

void backtrack(vector<vector<int>> &m, int n,vector<string> &str,int i,int j,string local){
    if(i==n-1 && j==n-1){
        str.push_back(local);
        return;
    }
    for(int k=0;k<4;k++){
        if(isValid(i+x[k],j+y[k],n,m)){
            m[i][j]=0;
            string temp=local;
            temp+=(movez[k]);
            backtrack(m,n,str,i+x[k],j+y[k],temp);
            m[i][j]=1;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n){
    vector<string> str;
    if(m[0][0]==0 || m[n-1][n-1]==0){
        str.push_back("-1");
        return str;
    }
    backtrack(m,n,str,0,0,"");
    
    if(str.empty()){
        str.push_back("-1");
    }
    return str;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cout<<"Enter the size of square grid(maze)\n";
    cin>>n;
    cout<<"Enter the maze :\n";
    vector<vector<int>> m(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    vector<string> soln=findPath(m,n);
    for(int i=0;i<soln.size();i++){
        cout<<soln[i]<<"\n";
    }
    
    

    return 0;
}