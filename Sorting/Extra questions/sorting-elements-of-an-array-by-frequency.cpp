//Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.
//https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int w=0;w<t;w++){
        int n;
        cin>>n;
        int arr[n];
        int hash[61][2];//given: range of data 1 to 60
        for(int i=0;i<61;i++){
            hash[i][0]=0;
            hash[i][1]=0;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
            hash[arr[i]][0]++;
            hash[arr[i]][1]=arr[i];
        }
        for(int i=0;i<61-1;i++){
            int count=0;
            for(int j=60-i;j>0;j--){
                if(hash[j][0]>hash[j-1][0]){
                    int temp=hash[j-1][0];
                    int temp2=hash[j-1][1];
                    hash[j-1][0]=hash[j][0];
                    hash[j][0]=temp;
                    hash[j-1][1]=hash[j][1];
                    hash[j][1]=temp2;
                    count++;
                    //cout<<"hi\n";
                }
            }
            if(count==0) break;
        }
        
        for(int i=0;i<61;i++){
            for(int j=0;j<hash[i][0];j++){
                cout<<hash[i][1]<<" ";
            }
        }
        cout<<"\n";

    }

    return 0;
}