// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

class Solution {
public:
// Ignore all the empty _ characters
// As soon as I encouter any character other than _, then s[i] and tar[j] should be same
// if tar[j]=='L', then i>=j condition must hold because in this case only we will be able to move the left piece towards left 
// similarly if tar[j]=='R' i <= j condition must hold, then only we can move the right piece in s towards right 
// At this point, the char at s[i] and tar[j] matches and we can move to next indices i++, j++;
// edge case: when either of i or j reaches end of string i.e if i==n or j==n then return true only if both i and j reaches end of string
/// ex: s=LLRR, tar = LL__
    bool canChange(string s, string tar) {
        int i = 0, j = 0, n = s.length();
        while(i<=n and j<=n){
            
            while(i<n and s[i]=='_') i++;
            
            while(j<n and tar[j]=='_') j++;

            if(i==n or j==n){ // edge case
                return i==n and j==n;
            }
            
            if(s[i] != tar[j]) return false; // char at s[i] and tar[j] should match 

            if(tar[j]=='L'){ // i >= j this condition should hold
                if(i < j) return false;
            }
            else{ // i <= j
                if(j < i) return false;
            }
            
            i++;
            j++;
        }

        return true;
    
    }
};

// TC: O(n),
// SC: O(n)