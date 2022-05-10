//Given a positive integer number N. The task is to generate all the binary strings of N bits.
#include<bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b) {
   long long res = 1;
   while (b > 0) {
       if (b & 1)
           res = res * a;
       a = a * a;
       b >>= 1;
   }
  return res;
}

//O(n*2^n) approach
void solve(int n){
    int x[n+1];
    for(int i=0;i<n+1;i++){
        x[i]=binpow(2,i);
    }
    int nz=binpow(2,n);
    for(int i=0;i<nz;i++){
        for(int j=n-1;j>=0;j--){
            cout<<(i/x[j])%2;
        }
        cout<<"\n";
    }
}

//O(2^n) approach
int hs=0;
void generateBS(string bstr,int n){
    if(n<1){
        cout<<bstr<<endl;
    }
    else{
        bstr[n-1]='0';
        generateBS(bstr,n-1);
        bstr[n-1]='1';
        generateBS(bstr,n-1);
    }

}
//same as above just in ascending order
void generateBS2(string bstr,int i,int n){
    if(i==n){
        cout<<bstr<<endl;
    }
    else{
        bstr[i]='0';
        generateBS2(bstr,i+1,n);
        bstr[i]='1';
        generateBS2(bstr,i+1,n);
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string bstr="";
    bstr.resize(n);
    // for(int i=0;i<n;i++){
    //     bstr+="0";
    // }


    //solve(n);
    //generateBS(bstr,n);
    generateBS2(bstr,0,n);


    return 0;
}