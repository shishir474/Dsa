Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

class Solution {
public:    
    void solve(int open, int close, int n, string s, vector<string>& res){
        if(s.length() == 2*n){
            res.push_back(s);
            return;
        }
        
        if(open < n){
            solve(open+1,close,n,s+"(",res);
        }
        if (close < open){
            solve(open,close+1,n,s+")",res);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(0,0,n,"",res);
        return res;
    }
};


TC: O(2^n), actually its less than 2^n, bcoz we are not moving in two directions every time, Since we have applied checks the number of recursive calls will be less than 2^n

SC: O(1) considering the fact that we are not taking into account the recursive call stack space, otherwise its O(2*n)-> max depth of the recursion tree