#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int lo, int mid, int hi){
    int n1=mid-lo+1, n2=hi-mid;
    int t1[n1], t2[n2];
    for(int i=0;i<n1;i++){
        t1[i]=arr[lo+i];
    }
    for(int i=0;i<n2;i++){
        t2[i] =  arr[mid+1+i];
    }
    
    int k=lo,i=0,j=0;
    while(i<n1 && j<n2){
        if(t1[i] <= t2[j]){
            arr[k++] = t1[i++];
        }
        else{
            arr[k++] = t2[j++];
        }
    }
    while(i<n1){
        arr[k++] = t1[i++];
    }
    while(j<n2){
        arr[k++] = t2[j++];
    }
    
}
void mergesort(int arr[], int lo, int hi){
    if(lo<hi){
        int mid=lo+(hi-lo)/2;
        mergesort(arr,lo,mid);
        mergesort(arr,mid+1,hi);
        merge(arr,lo,mid,hi);
    }
}
int main(){
    int arr[] = {8,4,5,3,65,-1,-100,23};
    int n = 8;
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}