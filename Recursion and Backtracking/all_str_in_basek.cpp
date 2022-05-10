#include<bits/stdc++.h>

using namespace std;

void generateKS(string kstr,int n,int k){
    if(n<1){
        cout<<kstr<<endl;
    }
    else{
        for(int i=0;i<k;i++){
            kstr[n-1]=i+'0';
            generateKS(kstr,n-1,k);
        }
    }

}
//in ascending order
void generateKS2(string kstr,int r,int n,int k){
    if(r==n){
        cout<<kstr<<endl;
    }
    else{
        for(int i=0;i<k;i++){
            kstr[r]=i+'0';
            generateKS2(kstr,r+1,n,k);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    string kstr="";
    kstr.resize(n);
    generateKS2(kstr,0,n,k);
    
    return 0;
}