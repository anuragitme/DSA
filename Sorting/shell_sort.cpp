#include<bits/stdc++.h>

using namespace std;

void swap(int arr[],int i,int k){
        int temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
}

void shellSort(int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int key=arr[i];
            int j=i;
            for(;j>=gap && arr[j-gap]>key;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=key;
        }
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
    shellSort(arr,n);
    arrOutput(arr,n);

    return 0;
}