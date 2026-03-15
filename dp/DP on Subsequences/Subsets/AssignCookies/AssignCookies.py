# extreme brute force:
# use linear search to find the best possible cookie


# Brute force
# Greedy Solution -- using binary search

class Solution:
    # approach:
    # 1. you sort the cookies
    # 2. for each child, you assign the smallest possible cookie that can satisfy them (lower_bound)
    # 3. This greedy choice works because - using a bigger cookie when a smaller one works may block a future child.

    # This binary_search function implements lower_bound functionality
    def binary_search(self, g, target):
        lo, hi = 0, len(g) - 1
        ans = -1
        while lo <= hi:
            mid = (lo + hi) // 2
            if g[mid] < target:
                lo = mid + 1
            else:
                ans = mid
                hi = mid - 1
        
        return ans

    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        s.sort()

        count = 0
        for i in range(len(g)):
            # check if there exists value >= g[i] in s
            idx = self.binary_search(s,g[i])
            if idx != -1:
                count+=1
                # remove the cookie
                del s[idx]
        
        return count
    
    # TC: O(nlogn) for sorting + O(n^2)
    # Once we find the desired cookie --we will need to remove it coz it can't be used anymore.
    # Removing it from the list effectively means we have to perform left shift on all the elements on the rhs, which is a very expensive operation
    
    
    

    
# Better Greedy Solution : 

class Solution:
    
    # 2 pointers (nested while)
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        # approach:
        # 1. Both arrays are sorted
        # i -> smallest appetite child not yet satisfied
        # j -> smallest unused cookie
        
        # if g[i] <= s[j]:
            # This jth cookie can satisfy the ith child
            # assign it and move both pointers
        
        # if g[i] > s[j]:
            # This cookie cannot satisfy any child (>= i) since appetites only increase
            # so, we can safely discard it -> j += 1
            
        # Idea is always satisfy the least greedy child first with smallest possible cookie.
        
        # logic is first we will sort both g and s lists in increasing order. 
        # The idea is we'll keep on moving the jth pointer until its not able to satisfy the ith child.
        # if jth cookie can't satisfy ith child -- then obvioulsy it wont be able to satisfy the childrens on the rhs of ith index because we have sorted the arrays in increasing order
        # and obviously the next child will have a greater appetite than the previous one. So there is no point of starting from the beginning for jth index.
        # It will move forward from the next index 

        # sort both the arrays
        g.sort()
        s.sort()

        # if the ith child is satisfied with jth cookie - we move on to the next child i+1 and next cookie j+1
        # otherwise if the ith child couldn't be satisfied with jth cookie -- we move on to the next cookie j+1

        num_of_children_satisfied = 0
        i = 0
        j = 0
        while i < len(g):
            while j < len(s) and s[j] < g[i]:
                j+=1
            
            if j == len(s):
                break

            num_of_children_satisfied += 1
            
            j += 1 # I cannot use the same cookie again
            
            i += 1  # move to the next child


        
        return num_of_children_satisfied
            
        # TC: O(nlogn) + O(mlogm) + O(n + m)
        # SC: O(1)
    
   
# Optimal Solution
 
class Solution:
    
    # 2 pointers (single while)
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        # uses the same concept as the above greedy solution
        # But this one has a simpler control flow and has one single while loop
        
        # logic is first we will sort both g and s lists in increasing order. 
        # The other way of thinking could be if the jth cookie is able to satisfy ith child, we simply move i and j one step
        # otherwise we simply move to the next cookie and the ith pointer remains at the same index. Because ith child is the child with minimal appetite amongst all childs.
        # So if the jth cookie cant satisfy ith child -- it cannot satisfy childrens on the rhs. 
        # This is only because we have sorted both the array

        # sort both the arrays
        g.sort()
        s.sort()

        # if the ith child is satisfied with jth cookie - we move on to the next child i+1 and next cookie j+1
        # otherwise if the ith child couldn't be satisfied with jth cookie -- we move on to the next cookie j+1

        num_of_children_satisfied = 0
        i = 0
        j = 0
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:
                # jth cookie can satisfy ith child
                num_of_children_satisfied+=1
                i+=1    # move on to next child
                
            j+=1 # move on to next cookie
            
        return num_of_children_satisfied
    
    
        # TC: O(nlogn) + O(mlogm) + O(n + m)
        # SC: O(1)
    
    
# NOTE: Altough better and the most optimal solutoin has same time complexity 
# most optimal one has better runtime performance (bcoz of one single while loop)