# Optimal Solution 2: Using Sliding Window with Hash Map
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {} # mp stores char and its frequency
        i = 0
        j = 0
        max_length = 0

        while j < len(s):
            
            mp[s[j]] = mp.get(s[j],0) + 1
            
            while mp[s[j]] > 1:
                mp[s[i]]-=1
                i+=1
            
            max_length = max(max_length, j - i + 1)

            j+=1

        return max_length

        # sliding window solution
        # TC: O(n)
        # SC: O(n) for mp -- assuming all the chars are unique
        # SC will be even less. It will be O(256) because string can have  English letters, digits, symbols and spaces.
        # map only has unique keys.
        


        
# Optimal Solution 2: Using Sliding Window with Hash Array
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # sliding window solution using hash array. THis is much faster and efficient than the previous sliding window solution using maps
        # because we aren't trimming one index at a time. We straight away move left pointer to the next index of the duplicate element

        # created and initialised hash_arr of size 256 
        # hash_arr will track the last seen index of each element
        hash_arr = [-1]*256

        l = 0
        r = 0
        max_length = 0

        while r < len(s):
            idx = ord(s[r])
            # have we encountered s[r] before and if it's part of our current window [l..r]?
            # in python, list indices must be integers. Get the ascii value using ord()
            if hash_arr[idx] != -1 and hash_arr[idx] >= l:
                l = hash_arr[idx] + 1

            max_length = max(max_length, r - l + 1)
            hash_arr[idx] = r
            r+=1

        return max_length

        # TC: O(n)
        # SC: O(256)