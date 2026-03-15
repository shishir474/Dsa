class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        res = [0] * (m+n)

        i  = 0
        j = 0
        k = 0

        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                res[k] = nums1[i]
                i+=1
            else:
                res[k] = nums2[j]
                j+=1
            
            k+=1

        while i < m:
            res[k] = nums1[i]
            i+=1
            k+=1

        while j < n:
            res[k] = nums2[j]
            j+=1
            k+=1


        # copy back res[] elements into nums1[]
        for i in range(len(res)):
            nums1[i] = res[i]

        # TC: O(m + n)
        # SC: O(m + n) extra space for res[]
        
        
        
        
        
# OPtimal SOlution 1: 
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        # Take 2 pointers - i & j
        # I will compare the greatest element of arr1[i] and smallest element of arr2[j]

        i = m - 1
        j = 0

        while i >= 0 and j < n:
            if nums1[i] > nums2[j]:
                # swap them 
                nums1[i], nums2[j] = nums2[j], nums1[i]
                i-=1
                j+=1
            else:
                break

        # now the elements are placed in their correct buckets - but still not placed in the correct sequence
        # sort both nums1 and nums2

        # extrac nums1[0:m] and sort it -- then copy this list arr1 back to nums1 and then copy nums2
        arr1 = sorted(nums1[0:m])
        nums2.sort()

        k = 0
        # copy arr1 back to nums1
        for j in range(m):
            nums1[k] = arr1[j]
            k+=1
        
        # copy nums2 back to nums1
        for j in range(n):
            nums1[k] = nums2[j]
            k+=1

        # TC: O(min(n,m)) + O(nlogn) + O(mlogm)
        # SC: O(1)
        
        
        
# Optimal Solution 2:
class Solution:
    def swap_if_greater(self, arr1, i, arr2, j):
        if arr1[i] > arr2[j]:
            arr1[i], arr2[j] = arr2[j], arr1[i]

    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        arr1 = nums1[0:m]

        gap = ceil((n + m) / 2)
        
        # a = 7 / 2 = 3.5
        # In python, even though both the operands are integer / will always return a float
        # In CPP 7 / 2 = 3
        # If you want float, we'd need cast one of the operands - 7 / 2.0 = 3.5
        # In python if you want integer, use // res - 7 // 2 = 3


        while gap > 0:
            i = 0
            j = i + gap

            while j < n + m:
                # if i < n and j >= n, compare arr1[i] and arr2[j - n]
                # if i >= n, ofcourse j will also be >=n , compare arr2[i-n], arr2[j-n]
                # if j < n, ofcourse i will also be < n, bcoz i is always < j
                if i < m and j>=m:
                    self.swap_if_greater(arr1, i, nums2, j - m)
                elif j < m:
                    self.swap_if_greater(arr1, i, arr1, j)
                else:
                    self.swap_if_greater(nums2, i - m, nums2, j - m)

                i += 1
                j += 1
            
            if gap == 1:
                break

            gap = ceil(gap/2)


        k = 0
        # copy elements back from arr1 to nums1
        for i in range(len(arr1)):
            nums1[k] = arr1[i]
            k+=1
        
        for i in range(len(nums2)):
            nums1[k] = nums2[i]
            k+=1
