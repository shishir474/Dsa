class Solution:
    def merge(self, arr, lo, mid, hi):
        # merges two sorted subarrays and counts inversions
        # arr[lo..mid] and arr[mid+1..hi] are sorted
        
        count = 0
        temp = [] # temporaray list to store the merged sorted array
        i = lo
        j = mid + 1
        while i <= mid and j <= hi:
            if arr[i] >= arr[j]:
                count += (mid - i + 1)
                temp.append(arr[j])
                j+=1
            else:
                temp.append(arr[i])
                i+=1
        
        # copy remaining elements from either halves
        while i <= mid:
            temp.append(arr[i])
            i+=1
        
        while j <= hi:
            temp.append(arr[j])
            j+=1
        
        # copy back the merged sorted array to original array
        for i in range(lo, hi + 1):
            arr[i] = temp[i - lo]
                
        return count
    
    
    # Utility Function on which recursion is called
    # returns the count of inversions in arr[lo..hi]
    def countInversionsHelper(self, arr, lo, hi):
        if lo >= hi:
            return 0
        
        mid = (lo + hi) // 2
        
        count = 0
        count += self.countInversionsHelper(arr, lo, mid) # arr[lo..mid]
        count += self.countInversionsHelper(arr, mid + 1, hi) # arr[mid+1..hi]
        
        # Calling recursion on both halves, will get both the halves sorted.
        # Merge both the sorted halves and count inversions during the merge process.
        count += self.merge(arr, lo, mid, hi)
        
        return count
        
        
    # Base Function
    def countInversions(self, arr):
        # Inversion definition: A pair (i, j) is an inversion if i < j and arr[i] > arr[j].
        # split the input arrray into two halves. Count the inversions in each half recursively.
        # Calling recursion on the halves, will get both the halves sorted.
        # Take 2 pointers, i =. 0, j = 0 for both halves. if nums1[i] > nums2[j] count+=(n - i)
        return self.countInversionsHelper(arr, 0, len(arr) - 1)
        
        
# Time Complexity: at each stage we are breaking our array into 2 halves -- so this is going to be log2n
# and then the merge operation which will take around O(n) time 
# so TC becomes O(n * logn) 

# SC: O(n) + O(log2n) -- recursive stack space (in worst case the depth of the recursion tree will be O(log2n))
# O(n) for temp array used during the merge operation. 
# Apart from this we are not using any extra space. We are just playing aroung with the indexes, not actually dividing the array.


# IMPORTANT OBSERVATION:
#NOTE: At the end of the day, the input array will be sorted. If u want to keep the input array intact, th