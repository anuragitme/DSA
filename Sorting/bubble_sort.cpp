#include<bits/stdc++.h>

using namespace std;

void swap(int *i,int* k){
        int temp=*i;
        *i=*k;
        *k=temp;
}

void bubbleSort(int arr[],int n){
    int change;
    for(int i=0;i<n;i++){
        change=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                change++;
            }
        }
        if(change==0){
            break;
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
    bubbleSort(arr,n);
    arrOutput(arr,n);

    return 0;
}