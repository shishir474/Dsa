// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        // odd length string can never be balanced
        if(n&1) return false;

        // left to right: checks for locked closing brackets
        int bal = 0;
        for(int i=0;i<s.length();i++){
            // if s[i] is ( or unlocked char increment bal
            // else s[i] is locked closing, and in order to balance this, the bal should be > 0. If not we cannot balance the string
            if (s[i]=='(' or locked[i]=='0') bal++;
            else bal--;  // locked closing

            // so if bal becomes < 0 at any point, we cannot balance
            if (bal < 0) return false;
        }

        // right to left : checks for locked opening brackets
        // reset balance
        bal = 0;
        for(int i=s.length()-1;i>=0;i--){
            if (s[i]==')' or locked[i]=='0') bal++;
            else bal--; // locked open, so we must have a closing bracket or an unlocked char

            if (bal < 0) return false; 
        }   

        return true;




    }
};

// TC: O(n) 2 for loops 
// SC:O(n)