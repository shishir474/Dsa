# https://leetcode.com/problems/longest-common-prefix/

# Brute force 

# we check for each prefix. shortest string in the list will be our starting prefix
# we compare this prefix with each string in the list
# we have a prefix, we iterate thru the list and compare each string with the prefix --> which is O(n*m) where n is the length of the list 
# and m is the length of the prefix
# string comparison is not O(1)
# overall time complexity becomes n * m * m
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # finding the shortest string
        shortest_len = float('inf')
        shortest_str = ""
        for s in strs:
            if len(s) < shortest_len:
                shortest_len = len(s)
                shortest_str = s
        
        
        for i in range(len(shortest_str)-1, -1, - 1):   # this loop is m
            res = shortest_str[0:i+1]  # s[0..i]
            # checking if res is a valid ans
            f = 0       
            for s in strs:      # this loop is n*m
                # comparing the prefix
                if res != s[0 : len(res)]:  # comparing strings is O(min(n,m))
                    f = 1
                    break

            if f == 0:
                return res

        
        return ""

        # TC: n * m * m where m is the length of the shortest string in the list
        # SC: O(1)
        
    
    
# Better Solution
# we compare characters column wise

class Solution:
    # we will compare characters column wise, 
    # compare 1st char, 2nd char, and so on across all strings
    
    # idea is we compare the characters of the 1st string with the remaining strings strs[1:]
    # we iterate thru each char of the 1st string
    # and compare it against the characters at the same position in the remaining strings strs[1:]
    # ofc, we need to check if i < len(s) -- ith char should exist in order to compare it
    # if the ith char doesn't exist or if there is a mismatch with strs[0] ith character -- we simply returns the strs[0][:i] i.e strs[0][0..i-1] prefix
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        for i in range(len(strs[0])):    # iterate thru all chars of 1st string
            # we will compare ith char of strs[0] and each string in list strs[1:]
            for s in strs[1:]:
                if i >= len(s) or s[i] != strs[0][i]:
                    return strs[0][:i]          # return first string strs[0] prefix [0..i-1]
                # if all char matches in s[i], we simply move to next char in strs[0][i]    

        return strs[0]