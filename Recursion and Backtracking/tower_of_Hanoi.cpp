#include<bits/stdc++.h>

using namespace std;

int steps=0;

void towerOfHanoi(int n,char st,char end ,char aux){
    if(n==1){
        cout<<st<<" to "<<end<<endl;
        steps++;
        return;
    }
    towerOfHanoi(n-1,st,aux,end);
    cout<<st<<" to "<<end<<endl;
    steps++;
    towerOfHanoi(n-1,aux,end,st);
}
int main(){
   int n;
   cin>>n;
   towerOfHanoi(n,'A','C','B');
   cout<<"Total no. of steps = "<<steps<<endl;

    return 0;
}