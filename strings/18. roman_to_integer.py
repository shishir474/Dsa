class Solution:
    def romanToInt(self, s: str) -> int:
        mp = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
            # 6 special instances
            'IV': 4,
            'IX': 9,
            'XL': 40,
            'XC': 90,
            'CD': 400,
            'CM': 900,
        }
        
        # MCMXCIV
        # 1000 + (-100) + 1000 + 10 + 

        val = 0
        
        i = 0
        while i < len(s):
            if i < len(s) - 1 and s[i:i+2] in mp:       # s[i..i+1]
                val += mp[s[i:i+2]]
                i+=2
            else:
                val += mp[s[i]]
                i+=1


        # for loop controls i automatically
        # i does not update, even if we update, for loop overwrites it in the next iteration.
        # Thus if you want manual control over i, use while loop
        # for i in range(len(s)):
        #     if i < len(s) - 1 and s[i] + s[i+1] in mp:
        #         print(mp[s[i]+s[i+1]])
        #         val += mp[s[i]+s[i+1]]
        #         i+=1
        #     else:
        #         print(mp[s[i]])
        #         val += mp[s[i]]

        return val
    
    # NOTE: Rules for Roman numbers
    # Symbols are added when smaller values follow larger ones (VI=6) and 
    # subtracted when smaller values precede larger ones (IV=4). 
    # Symbols I, X, C, and M can be repeated up to three times in a row (e.g XXX = 30).
    # No Repetition: V, L, and D are never repeated.
    # There is no Roman numeral for zero. 
    # Only one smaller numeral can precede a larger one for subtraction.

    # XLIX --> 49