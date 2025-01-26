// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    int minDeletionsToBalanceString(string s){
        stack<char> st;
        for(auto c: s){
            if (c!='(' and c!=')') continue; // s can contain lowercase characters as well
            if(c=='(')
                st.push('(');
            else{
                if(st.empty() or st.top()==')') st.push(c); // Push in 2 cases: when st is empty and st.top() is cloing bracket
                else st.pop();
            }
        }
        // number of remaining brackets indicate minimum deletions to make string balanced
        return st.size();
    }

    void solve(string s, int k, int idx, string tans, set<string>& ans, int open, int close, int n){
        // cout<<tans<<endl;
        if (k < 0 or open > n or close > open) return;
        if (idx==s.length()){
            if (k==0 and minDeletionsToBalanceString(tans) == 0){ // balanced string
                ans.insert(tans);
            }
            return;
        }
        
        if (s[idx]!='(' and s[idx]!=')'){ // lowercase only 1 option to pick
            solve(s, k, idx+1, tans+s[idx], ans, open, close, n);
        }
        else if (s[idx]=='('){ // 2 options for the opening bracket - pick and not pick 
            // if (open < n) // pick only when open < n
            solve(s, k, idx+1, tans+s[idx], ans, open+1, close, n);
            // not pick
            solve(s, k-1, idx+1, tans, ans, open, close, n);
        }
        else if(s[idx]==')'){ // 2 options for the closing bracket - pick and not pick 
            // if (close < open) // pick this closing bracket only when close < open
            solve(s, k, idx+1, tans+s[idx], ans, open, close+1, n);
            // not pick
            solve(s, k-1, idx+1, tans, ans, open, close, n);
        }

    }
    vector<string> removeInvalidParentheses(string s) {
        int k = minDeletionsToBalanceString(s);
        cout<<"k "<<k<<endl;
        int count= 0;
        for(auto c: s){
            if (c=='(' or c==')') count+=1;
        }
        int n = (count - k)/2; // count contains only the opening and closing brackets, cannot consider s.length() as string also contains lowercase letters
        
        set<string> ans;

        solve(s, k, 0, "", ans, 0, 0, n);

        vector<string> res;
        for (auto s: ans) res.push_back(s);
        
        return res;
    }
};

// // Solution contains of 2 steps:
// // First find the minimum number of deletions that needs to be done to make the string balanced. A balanced string requires 0 deletions
// // Apply backtracking based solution where you deletes that many min brackets and check in the base case if the string is balanced
//     // The recursion steps(else part) can be optimised, some kind of pruning is required to minimise the number of recursion calls.

// optimisations:
    // Apply opening bracket only when if(open < n) condition satisfies
    // Apply closing bracket only when if(close < open) condition satisfies

// This 2 conditions help us avoid a lot of unnecessary recursive calls
// Now in the base case check if you have deleted all k char and your string is balanced (getMinNumberOfDeletions(s) will return 0 for a balanced string)

// Instead of checking open < n and close < open apply this conditions in the base case -> This will speed up the sol a bit
// Not sure why is this working? But the sol gets accepted
