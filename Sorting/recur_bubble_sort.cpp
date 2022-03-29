#include<bits/stdc++.h>

using namespace std;

void swap(int *i,int *j){
        int temp=*i;
        *i=*j;
        *j=temp;
}

void recur_bubbleSort(int arr[],int n){
    if(n==0){
        return;
    }
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            swap(&arr[i],&arr[i-1]);
        }
    }
    recur_bubbleSort(arr,n-1);
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
    int n;
    cin>>n;
    int arr[n];
    arrInput(arr,n);
    recur_bubbleSort(arr,n);
    arrOutput(arr,n);

    return 0;
}