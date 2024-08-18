# https://leetcode.com/problems/valid-palindrome/

class Solution:
    def isPalindrome(self, s: str) -> bool:
        lst = []
        for i in s.lower():
            if ((ord(i)>=ord('a') and ord(i)<=ord('z'))  # if i is a lowercase or numeric char 
            or (ord(i)>=ord('0') and ord(i)<=ord('9'))):
                lst.append(i)
        
        # check if the lst is palindrom
        n = len(lst)        
        for i in range(len(lst)//2):
            if lst[i] != lst[n-1-i]: return False

        return True
# TC: O(n)
# SC: O(n)


# Using pythons inbuilt functions
class Solution:
    def isPalindrome(self, s: str) -> bool:
        newstr = ""
        for i in s.lower():
            if i.isalnum(): # alnum function checks if it is an alphanumberic character
                newstr+=i

        # check if the newstr is palindrom
        return newstr == newstr[::-1]
# TC: O(n)
# SC: O(n) for newstr


# constant space solution 

# https://www.youtube.com/watch?v=jJXJ16kPFWg&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=54

# use 2 pointers left and right initialised to 0 and n-1 initially. Compare the characters, but before compariing ensure that they are alphanumeric
# if the char dont match return false
# else move left pointer ahead one step and right pointer backward 1 step
# keep on doing this until all the left<=right or left hasnt crossed right
# keep in mind, the implementation of isalnum() function. Interviewer might ask that
class Solution:
    def isPalindrome(self, s: str) -> bool:
        l,r =0,len(s)-1
        while(l<=r):
            # if s[l] is an invalid char, move the left ptr
            while l<=r and s[l].isalnum()==False:
                l+=1
            # if s[r] is an invalid char, move the right ptr
            while l<=r and s[r].isalnum()==False:
                r-=1
            # both s[l] and s[r] are valid char, convert them in lowercase and then compare
            if s[l].lower() != s[r].lower():
                return False
            l+=1
            r-=1
        
        return True
    
# TC: O(n)
# SC: O(1) constant space solution