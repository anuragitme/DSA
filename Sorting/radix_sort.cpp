#include<bits/stdc++.h>

using namespace std;

void swap(int arr[],int i,int k){
        int temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
}
int maxVal(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }

    return max;
}
void countSort(int arr[],int n,int k){
    int c[10]={0};
    int b[n];
    for(int i=0;i<n;i++){
        c[(arr[i]/k)%10]++;
    }
    for(int i=1;i<10;i++){
        c[i]+=c[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[c[(arr[i]/k)%10]-1]=arr[i];
        c[(arr[i]/k)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=b[i];
    }

}
void radixSort(int arr[],int n){
    int max=maxVal(arr,n);

    for(int i=1;max/i>0;i*=10){
        countSort(arr,n,i);
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
    radixSort(arr,n);
    arrOutput(arr,n);

    return 0;
}