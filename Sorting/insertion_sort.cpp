#include<bits/stdc++.h>

using namespace std;

void swap(int *i,int* k){
        int temp=*i;
        *i=*k;
        *k=temp;
}


void insertionSort(int arr[],int n){
        for(int i=1;i<n;i++){
            for(int j=i;j>0;j--){
                if(arr[j]<arr[j-1]){
                    swap(&arr[j],&arr[j-1]);
                }
                else{
                    break;
                }
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
    insertionSort(arr,n);
    arrOutput(arr,n);

    return 0;
}