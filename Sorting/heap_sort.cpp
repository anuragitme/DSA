#include<bits/stdc++.h>

using namespace std;

int hs=0;

void swap(int *i,int* k){
        int temp=*i;
        *i=*k;
        *k=temp;
}

void maxHeapify(int arr[],int i){
    int largest=i;
    int lc=2*i;
    int rc=2*i+1;

    if(lc<=hs && arr[lc]>arr[i]){
        largest=lc;
    }
    if(rc<=hs && arr[rc]>arr[largest]){
        largest=rc;
    }
    if(i!=largest){
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr,largest);
    }
}

void buildMaxHeapify(int arr[]){
    for(int i=hs/2;i>=1;i--){
        maxHeapify(arr,i);
    }
}

void heapSort(int arr[]){
    buildMaxHeapify(arr);
    int temp=hs;
    for(int i=temp;i>=2;i--){
        swap(&arr[i],&arr[1]);
        hs--;
        maxHeapify(arr,1);
    }
    hs=temp;
}

void arrInput(int arr[],int n){
    arr[0]=INT_MAX;
    for(int i=1;i<n;i++){
        cin>>arr[i];
    }
}

void arrOutput(int arr[],int n){
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    
    int n;
    cin>>n;
    hs=n;
    int arr[n+1];
    arrInput(arr,n+1);
    heapSort(arr);
    arrOutput(arr,n+1);

    return 0;
}