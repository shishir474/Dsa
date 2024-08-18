# https://leetcode.com/problems/valid-anagram/

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # sol1
        # print(sorted(s)) # return a list of sorted characters
        # return sorted(s) == sorted(t)

        # Sol2
        # print(Counter(t))  # Counter returns a freq hashmap
        # return Counter(s) == Counter(t)

        # sol3 
        if len(s) != len(t):
            return False
        
        mp = defaultdict(int)
        for c in t:
            mp[c]+=1
        
        # iterate over all chars of s
        for c in s:
            if c not in mp: # if char is not found return False
                return False
            mp[c]-=1 # decrease freq of that c
        
        # iterate over mp and check all values should be 0
        for i in mp.values():
            if i != 0:
                return False
        return True