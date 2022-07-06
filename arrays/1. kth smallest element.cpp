#include <climits>
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}


// quick select algorithm
int kthSmallest(int arr[], int l, int r, int k)
{
    int pi = partition(arr,l,r);
    
    if(k > pi){
        return kthSmallest(arr,pi+1,r,k);
    }
    else if(k < pi){
        return kthSmallest(arr,l,pi-1,k);
    }
    else{
        return arr[pi];
    }
}

// Driver program to test above methods
int main()
{
	int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 3;
	cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k-1);
	return 0;
}

// solution 1: using sorting
// solution 2: using max priority_queue TC: O(nlogk), sc: O(k);
// soltuion 3: using quick select avg tc: O(N) and worst case tc: O(n^2)  THIS IS THE MAIN SOLUTION
