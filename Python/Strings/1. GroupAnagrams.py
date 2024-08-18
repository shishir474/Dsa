# https://leetcode.com/problems/group-anagrams/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        for i in strs:
            s = i
            # s.sort() # sort() cannot be directly applied on string
            lst_s = list(s)
            lst_s.sort()
            s = ''.join(lst_s)

            mp[s] = mp.get(s,[])
            mp[s].append(i)

        res = []
        for i in mp:
            res.append(mp[i])
        return res
             
             
             
# Clean code: complexity is same as the upper solution
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # defaultdict simplifies the code by eliminating the need to check if a key exists in the dictionary. It automatically initializes the list if the key is not present.
        mp = defaultdict(list)

        for i in strs:
            # s.sort() # sort() cannot be directly applied on string
            # sorted(s) converts a string into list of characters and sorts the list. The original string remain unaffected
            # join(lst) takes a list as a parameter and returns a string as an output
            s = ''.join(sorted(i))
            mp[s].append(i)

        # print(mp.keys())
        # print(mp.values())
        return list(mp.values())





# Optimised code: 
# 
# https://www.youtube.com/watch?v=vzdNOK2oB2E&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=52

from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # if the key is not present, defaultdict initialises key with an empty list
        mp = defaultdict(list)
        for i in strs:
            count = [0]*26 # a..z
            # construct the count array 
            for c in i:
                count[ord(c)-ord('a')] += 1
            
            # append the string corresponding to the count array
            # list cannot be a key in hashmap, lists are mutable, keys are immutable.
            # used defaultdict to avoid checking if the key exists in the hashmap 
            mp[tuple(count)].append(i)
        
        return mp.values()
    
    
# TC: O(m*n) solution where m is the number of strings in the list and n is the avg length of a string
# Earlier solution was based on sorting logic: 
    # Two strings are considered as anagrams if their sorted versions are exactly same
    # TC; O(m*nlogn) where  m is the number of strings in the list and n is the avg length of a string
    # we have to sort all the string 

# Since we only have char from a to z, we can do slightly better.
#  Intuition of the current solution
        # mp: freq array -> list of anagram string
        # since list cannot be used as key in python, used tuple as the key
        # tuples are immutable