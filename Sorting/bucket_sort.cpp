#include<bits/stdc++.h>

using namespace std;

void swap(float arr[],int i,int k){
        float temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
}

void bucketSort(float arr[],int n){
    vector<float> b[n];
    for(int i=0;i<n;i++){
        int bi=arr[i]*n;
        b[bi].push_back(arr[i]);
    }
    for(int i=0;i<n;i++){
        sort(b[i].begin(),b[i].end());
    }
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<b[i].size();j++){
            arr[k]=b[i][j];
            k++;
        }
    }

}

void arrInput(float arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void arrOutput(float arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    float arr[n];
    arrInput(arr,n);
    bucketSort(arr,n);
    arrOutput(arr,n);

    return 0;
}