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