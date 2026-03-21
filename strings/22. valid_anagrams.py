# https://leetcode.com/problems/valid-anagram/description/

# anagram definition:
# 2 strings are anagram if the have same set of characters with exact same frequency,
# which effectively means they both have same length and are identical when sorted
# s = "racecar"
# t = "rceacar"

# sorted_s = aaccerr
# sorted_t = aaccerr

# Using normal maps
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp: Dict[str,int] = {}
        for char in s:
            mp[char] = mp.get(char,0) + 1

        for char in t:
            if char not in mp or mp[char] == 0:
                return False
            else:
                mp[char]-=1
        
        # at this point, all frequencies should be zero in map
        for value in mp.values():
            if value != 0: return False
        
        return True
    
    # TC: O(n) + O(n)+ O(n) => O(n)


# Using defaultdict   
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = defaultdict(int)   # default factory int
        for char in s:
            mp[char]+=1

        for char in t:
            if char not in mp or mp[char] == 0:
                return False
            else:
                mp[char]-=1
        
        # at this point, all frequencies should be zero in map
        for value in mp.values():
            if value != 0: return False
        
        return True
    
    # TC: O(n) + O(n)+ O(n) => O(n)
    
# Using Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = Counter(s)
        for char in t:
            if char not in mp or mp[char] == 0:
                return False
            else:
                mp[char]-=1
        
        # at this point, all frequencies should be zero in map
        for value in mp.values():
            if value != 0: return False
        
        return True
