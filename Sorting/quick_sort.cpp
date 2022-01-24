#include<bits/stdc++.h>

using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;

}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
    int n;
    cout<<"Enter the size of array : "<<endl;;
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    quickSort(arr,0,n-1);
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}