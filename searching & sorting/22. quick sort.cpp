#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int lo, int hi){
    int pivot = arr[hi];
    int i=lo-1;
    for(int j=lo;j<hi;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[hi]);
    return i+1;
}

void quicksort(int arr[], int lo, int hi){
    if(lo<hi){
        int pi = partition(arr,lo,hi);
        quicksort(arr,lo,pi-1);
        quicksort(arr,pi+1,hi);
    }
}

int main(){
    int arr[] = {8,4,5,3,65,-1,-100,23};
    int n = 8;
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

TC: worst case occurs when when array is sorted bcoz in that case the array size only reduces by 1 each item, pivot is always placed at the last poisiton'
hence TC O(n^2)
Read TC and SC of all sorting algorithms and their code also