#include<bits/stdc++.h>

using namespace std;

void swap(int *i,int *j){
        int temp=*i;
        *i=*j;
        *j=temp;
}

void recur_insertionSort1(int arr[],int n){
    static int i=1;
    if(i==n){
        return;
    }
    for(int j=i;j>0;j--){
        if(arr[j]<arr[j-1]){
            swap(&arr[j],&arr[j-1]);
        }
        else{
            break;
        }
    }
    i++;
    recur_insertionSort1(arr,n);
    
}

void recur_insertionSort2(int arr[],int n){
    if(n<=1){
        return;
    }
    recur_insertionSort2(arr,n-1);
    int key=arr[n-1];
    int i=n-1;
    for(;i>0;i--){
        if(key<arr[i-1]){
            arr[i]=arr[i-1];
        }
        else{
            break;
        }
    }
    arr[i]=key;
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
    recur_insertionSort2(arr,n);
    arrOutput(arr,n);

    return 0;
}