# https://leetcode.com/problems/minimum-window-substring/description/

# Sol1 : Accepted solution
class Solution:
    # checks if mp2 is subset of mp1
    def isSubset(self, mp2, mp1):
        for i in mp2:
            if i not in mp1 or mp2[i] > mp1[i]:
                return False
        return True

    def minWindow(self, s: str, t: str) -> str:
        mp1, mp2 = {}, {}
        for i in t:
            mp2[i] = mp2.get(i,0) + 1

        ans=""
        ans_len = 1e9
        
        i = j = 0
        while j <len(s):
            # if s[j] in mp1:
            #     mp1[s[j]] += 1
            # else:
            #     mp1[s[j]] = 1
            mp1[s[j]] = mp1.get(s[j], 0) + 1
           
            if self.isSubset(mp2,mp1):
                # shrink as much as you can 
                while s[i] not in mp2 or mp1[s[i]]  > mp2[s[i]]:
                    mp1[s[i]]-=1
                    if mp1[s[i]] == 0: mp1.pop(s[i])
                    i+=1
                # now s contains no duplicates and has all the characters of t
                # print(s[i:j+1])
                if len(s[i:j+1]) < ans_len:
                    ans_len = len(s[i:j+1])
                    ans = s[i:j+1]

            j+=1
    
        return ans



# # SOl2 : Optimised

# Used dict.get(key, default) method to simplify and optimize the dictionary operations.
# Instead of using a separate function to check if mp2 is a subset of mp1, the main logic is now incorporated directly into the sliding window approach.

# https://www.youtube.com/watch?v=jSto0O4AJbM&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=51

class Solution:

    def minWindow(self, s: str, t: str) -> str:
        window_count, mp_t = {}, {}
        for i in t:
            mp_t[i] = mp_t.get(i,0) + 1

        # len, l, r
        ans = (float('inf'),None, None)

        # required: number of unique characters in t
        # formed: number of unique characters in curr window that match the desired count in t
        required, formed = len(mp_t), 0
        
        i = j = 0
        while j < len(s):
            # add the curr char to the window
            window_count[s[j]] = window_count.get(s[j], 0) + 1
           
            # if the current char count matches in t, then increment formed
            if s[j] in mp_t and window_count[s[j]] == mp_t[s[j]]:
                formed+=1

            # Try to contract the window
            while i<=j and formed==required:
                # update the ans if the curr ans's length is smaller than the prev computed ans
                if j-i+1 < ans[0]:
                    ans = (j-i+1,i,j)
                
                # Remove the ith char from the window
                window_count[s[i]]-=1
                if s[i] in mp_t and window_count[s[i]] < mp_t[s[i]]:
                    formed-=1
                
                # move the left pointer
                i+=1

            # keep expanding the window by moving the right pointer
            j+=1
    
        # return the smallest window or an empty string if no valid window was found
        return "" if ans[0]==float('inf') else s[ans[1]:ans[2]+1]


# where m and n are the length of s and t respectively
# TC: O(m+n)
# SC: O(m+n)