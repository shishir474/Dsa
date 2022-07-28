Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

class Solution {
public:
    bool isPalindrome(string s,int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    void solve(int i, string s, vector<string>& output, vector<vector<string> >& res){
        int n=s.length();
        if(i==n){
            res.push_back(output);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(isPalindrome(s,i,j)){
                output.push_back(s.substr(i,j-i+1));
                solve(j+1,s,output,res);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> output;
        solve(0,s,output,res);
        return res;
    }
};