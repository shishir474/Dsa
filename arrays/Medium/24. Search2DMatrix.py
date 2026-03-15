class Solution:
    def binary_search(self, arr, target):
        lo, hi = 0, len(arr)-1
        while lo <= hi:
            mid = (lo + hi) // 2
            if arr[mid] == target: 
                return True
            elif arr[mid] < target:
                lo = mid + 1
            else:
                hi = mid - 1
        
        return False


    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # approach: First get to the desired row and then search in that row
        # Used binary search to find the desired row. 
        # if target < first element of mid row, then search in upper half else if target > last element of mid row, search in lower half else search in mid row
        # second binary search to search in the desired row
        # TC: O(logn + logm) where n is number of rows and m is number of columns
        # SC: O(1)
        
        n = len(matrix)
        m = len(matrix[0])
         # n X m matrix 
        lo = 0
        hi = n - 1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if target < matrix[mid][0]:
                hi = mid - 1
            else:
                if target > matrix[mid][m-1]:
                    lo = mid + 1
                else:
                    # search in the mid row - only this row can contain the target element. That's the only possibility
                    return self.binary_search(matrix[mid], target)
        
        return False