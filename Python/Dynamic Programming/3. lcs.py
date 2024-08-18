class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n,m = len(text1), len(text2)
        # (n+1)*(m+1) sized matrix
        # 1st row and 1st col initialised with 0 - base case
        t = [[0 for j in range(m+1)] for i in range(n+1)]
        
        for i in range(1,n+1):
            for j in range(1,m+1):
                # if ith and jth char are equal
                if text1[i-1]==text2[j-1]:
                    t[i][j] = 1 + t[i-1][j-1]
                else:
                    t[i][j] = max(t[i-1][j], t[i][j-1])
        
        return t[n][m]

# TC: O(n*m)
# SC: O(n*m)