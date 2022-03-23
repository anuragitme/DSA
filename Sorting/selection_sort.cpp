#include<bits/stdc++.h>

using namespace std;

void swap(int arr[],int i,int k){
        int temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
}

void selectionSort(int arr[],int n){
    int k;
        for(int i=0;i<n;i++){
            k=i;
            for(int j=i+1;j<n;j++){
                if(arr[k]>arr[j]){
                    k=j;
                }
            }
            swap(arr,i,k);
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
    int n;
    cin>>n;
    int arr[n];
    arrInput(arr,n);
    selectionSort(arr,n);
    arrOutput(arr,n);

    return 0;
}