
# naive pattern matchin:
# O((n - m + 1) * m) where n and m is the length of input_str and sub.
# If we simplify it, tc becomes O(n * m) 
# n - m + 1 is the number of times pattern slides over the text.
# THis is highly inefficient coz it involves unnecessary char comparisons, which could be total avoided using hash comparisons

class Solution:
    def rabin_karp(self, input_str, sub):
        res = []
        for i in range(len(input_str) - len(sub) + 1):
            j = 0
            while j < len(sub) and input_str[i+j] == sub[j]:
                j+=1
            if j == len(sub):
                res.append(i)
        
        return res
                

          
def main():
    sol = Solution()
    input_str = "ccbbcccbghccbj"
    sub = "ccb"
    
    res = sol.rabin_karp(input_str, sub)
    print(res)
    
if __name__ == "__main__":
    main()

#NOTE: Intuition https://www.youtube.com/watch?v=yFHV7weZ_as

# rabin karp solves this much more efficiently
# uses the concept of rolling hash funtion. 
# Instead of comparing the strings, we compare the hash values and only if the hash matches, we perform the comparison(cross verifying) just to make sure that it isn't the case of hash collision
# hash comparison is much faster than string comparisons.
# worst case would be if the hash value always matches. In this case we will have to cross verify again and again essentially making it worse as the naive algorithm
# so the algorithm efficiency depends on the robustness of the hash function
# worst case complexity : O((n - m + 1 ) * m) + O(m)
# On average, Rabin karp is usually much efficient algorithm.

# we first compute the hash of the sub. 
# Then we compute the hash of the string window of size equivalent to sub. 
# while updating the window, we update the hash of the string window by removing the contribution of the leftmost char and adding the contributoin of newly added char in the window.
# TC: O(n - m + 1) + O(m) which effectively is O(n + m)
# O(n - m + 1) this is the no of times pattern slides over the text and O(m) for hash computation of pattern


# Implementation Pending