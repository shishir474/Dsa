from typing import List         # import List type from Python's typing module

# Python is dynamically typed language. Thus providing type hint is completely optional.
# Although adding type info in the input arguments and return type is recommended as good practise in production/large codebases.
# Reason is : provides better readability

#Python type hints are not enforced at runtime. They are mainly used by static type checkers and IDEs to detect type errors before execution.
# If we want to enforce this at runtime, we must enforce it manually
# def add(x: int, y: int) -> int:
#     return x + y

# add("a", "b")   # static checker warns

# Python chooses this design instead of strict typing (like Java or C++), which is a really interesting design decision.


class Solution:
    def isPalindrome(self, lo, hi, input_str) -> bool:
        i, j = lo, hi
        while i < j:
            if input_str[i] != input_str[j]:
                return False
            i+=1
            j-=1
        return True
        
    def generateAllPalindromePartitions(self, input_str: str ) -> List[List[str]]:
        res = []
        temp_list = []
                
        def helper(idx):
            if idx >= len(input_str):
                res.append(temp_list[:])    # copy the temp_list in res. We store a copy of temp_list bcoz python stores references of inner lists which will undergo modification during recursion
                return
            
            for i in range(idx, len(input_str)):
                if self.isPalindrome(idx, i, input_str):     # we can precompute this 
                    temp_list.append(input_str[idx:i+1])
                    helper(i+1)
                    temp_list.pop()         # remove the last appended string - standard backtracking practise
                    
                    
        helper(0)
        return res
        
    # TC: for each index: we have 2 possibilities - take it or leave it
    # leading to 2^n possible combinations & O(n) work is required to check palindrome.
    # So the TC is O(n * 2^n). This could be optimized further by precomputing the info s[i..j] is a palindrome or not. 
    # which will bring down the complexity to O(n^2) + O(2^n)
    
    # SC: O(n) recursive stack space + O(n * 2^n) storage space, assuming n is the length of each partition and 2^n no of partitions are possible in total
        
    def driver(self):
        input_str = "aabb"
        
        res = self.generateAllPalindromePartitions(input_str)
        
        for lst in res:
            for i in lst:
                print(i, end = ' ')
            print()
            
        
sol = Solution()
sol.driver()

