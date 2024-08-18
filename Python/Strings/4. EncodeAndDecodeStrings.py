# https://www.youtube.com/watch?v=B1k_sxOSgv8&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=58

# https://www.lintcode.com/problem/659/

# There are multiple ways of encoding a string. Basically we need to choose a delimiter such that we are able to distinguish the start and the end of a particular word
# 1 solution:
    # Use # as delimter. But the question states that we can have all valid 256 characters in the string. Thus we cannot use # alone, it will not work in case the string contains # itself
# 2 solution:
    # 4lint4code4love3you -> basically length of the string followed by the string. Again same problem can occur where the original string contains a numerical char
    
# 3rd solution: Working
    # Use length+# as delimiter
    # 4#lint4#code4#love3#you

    # start scanning the string until you encouter a #. This will be your length. Now capture length chars from the next idx(curr idx will be at #) Move the ptr to curr_idx+length+1.

# 4th solution:
# We could also have stored the length of each word in a list and use that list while decoding. But this requires extra space. Questions requirement is to not use any state variable

# Input: ["lint","code","love","you"]
# Output: ["lint","code","love","you"]
# Explanation:
# One possible encode method is: "lint:;code:;love:;you"


class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """
    def encode(self, strs):
        if len(strs)==0:
             return ""

        encodedstr = ""
        for i in strs:
            encodedstr+=str(len(i))+"#"+i
        return encodedstr


    """
    @param: str: A string
    @return: decodes a single string to a list of strings
    """
    def decode(self, str):
        if len(str)==0:
            return []
        # write your code here
        ans = []
        i = 0
        while i<len(str):
            j = i
            while str[j]!='#':
                j+=1
            length = int(str[i:j])
            ans.append(str[j+1, j+length+1])
            i = j + length + 1

        return ans

# TC: O(n) for both encode and decode
# SC: O(1)