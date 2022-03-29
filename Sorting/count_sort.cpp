#include<bits/stdc++.h>

using namespace std;

void swap(int arr[],int i,int k){
        int temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
}

void countSort(int arr[],int n,int k){
    int c[k+1],b[n];
    for(int i=0;i<=k;i++){
        c[i]=0;
    }
    for(int i=0;i<n;i++){
        c[arr[i]]++;
    }
    for(int i=1;i<n+1;i++){
        c[i]+=c[i-1];
    }
    for(int i=n-1;i>=0;i--){
        // c[arr[i]]--;
        // b[c[arr[i]]]=arr[i];
        b[c[arr[i]]-1]=arr[i];
        c[arr[i]]--;
        
    }
    for(int i=0;i<n;i++){
        arr[i]=b[i];
    }
}

void arrInput(int arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void arrOutput(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int arr[n];
    arrInput(arr,n);
    countSort(arr,n,k);
    arrOutput(arr,n);

    return 0;
}