# https://leetcode.com/problems/count-and-say/

# countAndSay(1) = "1"
# countAndSay(n) is the run-length encoding of countAndSay(n - 1).

class Solution:
    # computes the Run Length Encoding of string s
    def rle(self, s: str) -> str:
        n = len(s)
        res = ""
        i = 0
        while i < n:
            j = i
            while j < n and s[i] == s[j]: 
                j+=1
            freq = j - i
            res += str(freq) + s[i]
            i = j

        return res
        
    def countAndSay(self, n: int) -> str:
        print(n)
        if n == 1:
            return "1"
        # RLE Of "1211" --> 111221 
        # basically {freq_char}
        return self.rle(self.countAndSay(n-1))
    
# TC: O(n^2): for each recursion call O(n) work is done and there are O(n) such calls. 
# Hence overall complexity: O(n^2)
# SC: O(n) recursive stack space


# Iterative Solution:
class Solution:
    # computes the Run Length Encoding of string s
    def rle(self, s: str) -> str:
        n = len(s)
        res = ""
        i = 0
        while i < n:
            j = i
            while j < n and s[i] == s[j]: 
                j+=1
            freq = j - i
            res += str(freq) + s[i]
            i = j

        return res
        
    def countAndSay(self, n: int) -> str:
        dp = [""]*(n+1)
        dp[1] = "1"     # base case
        for i in range(2,n+1):
            dp[i] = self.rle(dp[i-1])

        return dp[n]
    
        
# TC: O(n^2): for loop runs n times and for each iteration, O(n) work is being done in order to compute rle (run length encoding)
# Hence overall complexity: O(n^2)
# SC: O(n) for dp array. Thru iterative solution, we got rid of extra space for recursion stack