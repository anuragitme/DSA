#include<bits/stdc++.h>

using namespace std;

void swap(int *i,int *j){
        int temp=*i;
        *i=*j;
        *j=temp;
}

void recur_selectionSort(int arr[],int n){
    if(n==0){
        return;
    }
    int max=n-1;
    for(int i=n-2;i>=0;i--){
        if(arr[max]<arr[i]){
            max=i;
        }
    }
    if(max!= n-1){
        swap(&arr[max],&arr[n-1]);
    }
    recur_selectionSort(arr,n-1);
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
    recur_selectionSort(arr,n);
    arrOutput(arr,n);

    return 0;
}