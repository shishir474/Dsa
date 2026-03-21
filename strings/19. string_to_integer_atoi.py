# https://leetcode.com/problems/string-to-integer-atoi/
# first step: remove all trailing and leading white spaces
# Building integers is always an optimal solutoin. Hence we will build integers directly from the string
# based on if s[0]=='+' or s[0]=='-' : set the starting point and sign bit
# start iteratng from the starting point. 
# Remeber we will iterate only till the point we get valid digits. if its a non digit char, we break
# build the number: num * 10 + int(s[i])
# but before building the number, added an overflow check to ensure the number stays within limit -- edge case presented in the problem statement
# and finally we return sign * num, which simply means, if sign == 1 return num else if sign == -1 return -1*num

class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()       # remove leading & trailing whitespaces
        
        if len(s) == 0:
            return 0

        # # now the first char could be in ('+', '-', [0-9], [a-z], [A-Z])
        i = 0
        sign = 1
        if s[0] == '+' or s[0] == '-':
            if s[0] == '-':
                sign = -1
            i+=1

        num = 0
        while i < len(s) and s[i].isdigit():
            digit = int(s[i])
            # check overflow before adding
            if num * 10 + digit > 2**31 - 1:
                return 2**31 - 1 if sign == 1 else -2**31
                
            num = num*10 + digit        # always better to construct a number than a string
            i += 1

        return sign*num
    
# TC: O(N)
# SC: O(1)
    