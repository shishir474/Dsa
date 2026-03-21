# Before talking about KMP algo, lets see how the naive algorithm to solve the same problem works.
# we will slide the pattern over the text and match the corresponding chars in each iteration 
# and if a match is found we will note its index

# pattern = "ababcabab"
# text = "bababababcababcabab"
# n - m + 1 potential starting points in text leading to those many iterations
# for each iteration: we compare text[i+j] & pattern[j] which will take O(m)
# overall tc: O(n - m + 1) * m --> simplifying this will give the complexity: O(N * M)

# KMP solves this problem in linear time complexity
# It first pre-processes the pattern to find what is called a prefix suffix table or the longest prefix suffix.
# It just verifies whether a prefix is repeating somewhere in the pattern or not.
# By doing this we can prevent unncessary comparisons while performing the search.

# pattern = a b a b c a b a b
# lps[] =   0 0 1 2 0 1 2 3 4   
# 0th index: this 'a' is not repeating before it so lps[0] = 0
# 1st index: same with 'b', lps[1] = 1
# 2nd index: this 'a' is repeating again with the first letter, lps[2] = 1
# 3rd index: this 'ab' is repeating, thus lps[3] = 2

# NOTE: for each index, we are essentially interested in knowing the length of the longest prefix which is also a suffix in that string
# for instance, if we talk about this string: abab "ab" is the longest prefix which is also present as suffix.
# Hence the length of longest prefix which also exists as suffix is 2.

# 4th index: there is no such prefix, thus lps[4] = 0

def get_lps(pattern: str):
    m = len(pattern)
    lps = [0]*m
    
    i,j = 1,0
    while i < m:
        if pattern[i] == pattern[j]:
            j+=1
            lps[i] = j 
            i+=1
        else:
            if j!=0:
                j = lps[j - 1]
            else:
                lps[i] = 0
                i+=1
                
    return lps
                
# precomputing lps array takes O(n) where n is the pattern length

# now lets see how this helps in KMP algo for pattern matchin
# i = 0 on text and j = 0 on pattern and we start matching corresponding characters

def kmp(text, pattern):
    n = len(text)
    m = len(pattern)
    i, j = 0,0
    
    lps = get_lps(pattern) # precomputation
    
    while i < n:
        if text[i] == pattern[j]:
            i+=1
            j+=1
        else:
            if j != 0:
                j = lps[j-1]
            else:
                i+=1
        if j == len(pattern): # if found a match
            print("pattern found at index: ", i - j)
            j = lps[j-1]
    
 
# TC: O(n) for precomputation + O(n) for while loop
# Overall complexity: O(n)
    
