  Merge Sort

  This algo basically uses divide and merge strategy.
  arr[] = {3,1,2,4,1,5,2,6,4}

  This arr has 9 elements. If I have to ask you a question in how many ways can you divide this arr into 2 parts such that both of them has almost got an equal no of elements
  Since the arr has odd elements, either we can divide it 5|4 or 4|5
  Lets go ahead with the 5|4 strategy 

arr1[] = {3,1,2,4,1} arr2[] = {5,2,6,4}

algo will further divide the arrays 

arr1[] = {3,1,2} arr2[] = {4,1}
arr1[] = {3,1}, arr2[] = {2}        arr1[] = {4}, arr2[] = {1}
arr1[] = {3}, arr2[] = {1}

can a single element be further divide? No its already sorted 


Instead of dividing the arrays, I will play around indexes. 


TC: There is an n sized array which is getting divided into 2 halves each time. Whenever it keeps on getting divided by 2, the time complexity is log (base 2 n) i.e log2n
assume n = 6 --> 8,8, --> 4,4 --> 2,2 --> 1,1
4 steps 
2^4 = 16 

log2(16) = 4


void mergeSort(vector<int> &arr, int lo , int hi){
    if(lo >= hi) return;            // if lo == hi || lo > hi      -- arr[lo..hi] is already sorted 
    int m = (lo + hi)/2;
    mergeSort(arr, lo, m);
    mergeSort(arr, m + 1, hi);

    mergeTwoSortedArrays(arr, lo, m, hi);

}
          lo       m                  hi  
arr1[] = {3,1,2,4,1} arr2[] = {5,2,6,4}
          left                right
         {1,1,2,3,4} arr2[] = {2,4,5,6}  

void mergeTwoSortedArrays(vector<int> &arr, int lo, int m, int hi){
    // using temp[] for merging and 2pointer technique
    vector<int> temp;
    // [lo .. mid]
    // [mid+1 .. hi]
    int left = lo, right = m + 1;
    while(left <= m && right <= hi){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= m){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= hi){
        temp.push_back(arr[right]);
        right++;
    }

    // copy the elements into arr from temp
    for(int i = lo; i <= hi; i++){
        arr[i] = temp[i - lo];
    }
}


// we could have optimised the space complexity in merging 2 sorted arrays, but that would increase the time complexity 
        2ptrs + extra_space         2pointers + O(1) space                          Gap Method 
TC      O(n + m)                    O(min(n,m)) + O(nlogn) + O(mlogm)                  O((n + m)log2(n+m))
SC      O(n + m)                    O(1)                                                O(1)


The time complexity of merge sort is --
at each step we are dividing n into n/2 so thats going to be log2n
and then merging the n sized array 
and if you see above the best approach to merge them would be using 2ptrs+extra space becuae this has the lowest time complexity as compared to other 2 appraoches, though the other two approaches offers better space complexity.
But thats the price Im willing to pay 

Hence going ahead with the first merging strategy 
OVerall TC of merge Sort: O(nlog2n)
SC: O(n) -- the merge step is creating a temp[] and in the worst case the size of this will be O(n)

Now we know why choosing the extra space method here makes more sense, because overall it gives us the better time complexity.


If the question is about merging 2 sorted arrays, discuss all the 3 approaches
But if the question asks you to do merge sort, always use the 2pointers + extra space solution as your mergin strategy.