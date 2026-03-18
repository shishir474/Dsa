from collections import deque
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums2)
        res = [0] * n
        res[n-1] = -1
        st = deque()
        st.append(nums2[n-1])
        
        # iterating in reverse direction -- from n-2 to 0 th
        for i in range(n-2, -1, -1):
            if st[-1] > nums2[i]:
                res[i] = st[-1]
            else:
                # keep on popping until stack is non empty and stack top <= arr[i]
                while st and st[-1] <= nums2[i]:
                    st.pop()
                
                if not st:      # if stack is empty
                    res[i] = -1
                else:           # set stack top as res[i]
                    res[i] = st[-1]

            st.append(nums2[i])

        return res
    
    
# Compressed version of the above solutoin:
# Uses the same logic: we just merged if and else into one single block. 
# We dont need to handle them separately

from collections import deque
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums2)
        res = [0] * n
        res[n-1] = -1
        st = deque()
        st.append(nums2[n-1])
        
        # iterating in reverse direction -- from n-2 to 0 th
        for i in range(n-2, -1, -1):
            # keep on popping until stack is non empty and stack top <= arr[i]
            while st and st[-1] <= nums2[i]:
                st.pop()
            
            if not st:      # if stack is empty
                res[i] = -1
            else:           # set stack top as res[i]
                res[i] = st[-1]

            st.append(nums2[i])

        return res
    
# can do one more enhancement
# we dont even need to process last eleemnt separately. 
# It can be handled in the same for loop

from collections import deque
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums2)
        res = [0] * n
        st = deque()

        # iterating in reverse direction -- from n-2 to 0 th
        for i in range(n-1, -1, -1):
            # keep on popping until stack is non empty and stack top <= arr[i]
            while st and st[-1] <= nums2[i]:
                st.pop()
            
            if not st:      # if stack is empty
                res[i] = -1
            else:           # set stack top as res[i]
                res[i] = st[-1]

            st.append(nums2[i])

        return res