#include<bits/stdc++.h>

using namespace std;
// this is efficient rat maze soln 
// in this we make(some of) that vertex 0 from which it is not possible to reach final destin;

int x[4]={1,0,0,-1},y[4]={0,1,-1,0};
string movez="DRLU";

bool isValid(int i,int j, int n,vector<vector<int>> &m){
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }
    if(m[i][j]==0){
        return false;
    }
    return true;
}
void display(vector<vector<int>> &m, int n){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int backtrack(vector<vector<int>> &m, int n,vector<string> &str,int i,int j,string local,int p){
    if(i==n-1 && j==n-1){
        str.push_back(local);
        return 1;
    }
    int flag=0,nosol=0;
    for(int k=0;k<4;k++){
        display(m,n);
        if(k==(3-p)) continue;
        if(isValid(i+x[k],j+y[k],n,m)){
            m[i][j]=2;
            string temp=local;
            temp+=(movez[k]);
            if(m[i+x[k]][j+y[k]]==1){
                if(backtrack(m,n,str,i+x[k],j+y[k],temp,k)) flag=1;
            }
            m[i][j]=1;
            nosol=1;
        }
        
    }
    m[i][j]=1;
    if(nosol==0) m[i][j]=0;
    return flag;
}

vector<string> findPath(vector<vector<int>> &m, int n){
    vector<string> str;
    if(m[0][0]==0 || m[n-1][n-1]==0){
        str.push_back("-1");
        return str;
    }
    int x= backtrack(m,n,str,0,0,"",0);
    
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