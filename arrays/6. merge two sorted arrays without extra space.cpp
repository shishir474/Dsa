class Solution{
public:
int getGap(int n){
    if (n<=1) return 0;
    return ceil(n/(2*1.0));
}
void merge(int arr1[], int arr2[], int n, int m) {
    // code here
    int i,j;
    
    for(int gap = getGap(m+n); gap>0 ; gap = getGap(gap)){
        for(i=0;i+gap<n; i++){
            if (arr1[i] > arr1[i+gap]) swap(arr1[i], arr1[i+gap]);
        }
        for(j = gap>n?gap-n:0; i<n and j<m; i++,j++){
            if (arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);
        }
        if (j<m){
            for(int j=0;j+gap<m;j++){
                if (arr2[j] > arr2[j+gap]) swap(arr2[j], arr2[j+gap]);
            }
        }
    }
    
}

};


// solution1: take array of size m+n, copy elements of both the arrays into the new array, sort the new array and then place the elements back in the first and second array
// TC: (n+m)log(n+m) + o(n) + o(m), sc: O(n+m)

// solution 2: insertion sort, intuition: both the arrays are sorted
// TC: O(n*m), sc: O(1);
void merge(int arr1[], int arr2[], int n, int m) {
  // code here
  int i, k;
  for (i = 0; i < n; i++) {
    // take first element from arr1 
    // compare it with first element of second array
    // if condition match, then swap
    if (arr1[i] > arr2[0]) {
      int temp = arr1[i];
      arr1[i] = arr2[0];
      arr2[0] = temp;
    }

    // then sort the second array
    // put the element in its correct position
    // so that next cycle can swap elements correctly
    int first = arr2[0];
    // insertion sort is used here
    for (k = 1; k < m && arr2[k] < first; k++) {
      arr2[k - 1] = arr2[k];
    }
    arr2[k - 1] = first;
  }
}



//solution 4: gap method
// TC: O(n+m)log(n+m)	Sc: O(1)



// solution3 TC:O(m+n) sc:O(m+n);

  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if (nums1[i] < nums2[j]){
                temp[k++] = nums1[i++];
            }
            else{
                temp[k++] = nums2[j++];
            }
        }
        
        while(i<m){
            temp[k++] = nums1[i++];
        }
        
        while(j<n){
            temp[k++] = nums2[j++];
        }
        
        for(int i=0;i<m+n;i++){
            nums1[i] = temp[i];
        }
        
        
    }