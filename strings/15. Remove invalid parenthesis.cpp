    class Solution {
public:
    // returns the minimum no.of paranthesis that needs to be removed to make the string balanced
    
    // first get the minimum no. of removals that are allowed, ex: ()())() In this example we can only remove 1 brackets. So get The minimal no. of removals allowed
    // Now basically we know that we can remove at max rem no. of brackets. So remove one parenthesis (ith one) and call recursion on the remaining string(left part + right part) and pass the rem as rem - 1(utilised one removal)
    // base case: if no. of rem = 0, it means we are not allowed to remove any more brackets => potentially our string should be balanced at this point(getMin() should return 0). call getMin() to get the minimal no. of removals to be performed to balance the string. If it returns 0 => our string is balanced already
    // If the string is balanced and we have not included it in our ans set, then insert it into our ans set
    // Our ans shouldn't contain duplicates, So used set.
    
    // Solution is correct but still getting TLE
    // Oprimisation that we could apply is we process only the unprocessed strings(left+right). SO maintain a set2 to keep track whether we have processed a particular string. IF it is not present in set2 => not processed yet, Insert into the set2 & call reucrsion on this
    

Time Complexity : O(2^N)O(2 
N
 ) since in the worst case we will have only left parentheses in the expression and for every bracket we will have two options i.e. whether to remove it or consider it. Considering that the expression has NN parentheses, the time complexity will be O(2^N)O(2 
N
 ).
Space Complexity : O(N)O(N) because we are resorting to a recursive solution and for a recursive solution there is always stack space used as internal function states are saved onto a stack during recursion. The maximum depth of recursion decides the stack space used. Since we process one character at a time and the base case for the recursion is when we have processed all of the characters of the expression string, the size of the stack would be O(N)O(N). Note that we are not considering the space required to store the valid expressions. We only count the intermediate space here.




class Solution {
public:
     int getMin(string s){
      stack<char> st;
      for (int i=0;i<s.length();i++){
          if (s[i] == '('){
              st.push(s[i]);
          }
          else if(s[i] == ')'){
              if(st.empty()){
                  st.push(s[i]);
              }
              else if(st.top() == ')'){
                  st.push(s[i]);
              }
              else{
                  st.pop();
              }
          }
      }
        
        return st.size();  
    }
    
    void solve(string s, int i, int open, int close, string ans, vector<string>& res, int mr, int n){
        // cout<<open<<" "<<close<<endl;
        
        if(mr<0 || open>n || close>open) return;
        if(i>=s.length()){
            // cout<<ans<<endl;
            if(open==close and find(res.begin(),res.end(),ans)==res.end()){
                res.push_back(ans);
            }
            return;
        }
        
        
        if(s[i]=='('){
            solve(s,i+1,open+1,close,ans+"(",res,mr,n);
            solve(s,i+1,open,close,ans,res,mr-1,n);
        }
        else if(s[i]==')'){
            solve(s,i+1,open,close+1,ans+")",res,mr,n);
            solve(s,i+1,open,close,ans,res,mr-1,n);
        }
        else{
            solve(s,i+1,open,close,ans+s[i],res,mr,n);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int mr=getMin(s);
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]==')') c++;
        }
        int n = (c-mr)/2;
        vector<string> res;
        solve(s,0,0,0,"",res,mr,n);
        return res;
    }
};







1249. Minimum Remove to Make Valid Parentheses-> return a single string

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 

SOLUTION:
Figure out all the faulty bracktes & then 
if it is ipening and there is no corresponding closing, then its faulty bracket or if its closing & there is not corresponding opening then also it is a faulty bracket. Push all the faulty indices in the set
Now 


Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        int close = 0, open = 0;
        set<int> set;
        
        for(int i=0;i<s.length();i++){
            if (s[i]=='('){
                st.push(i);
            }else if(s[i]==')') {
                if (!st.empty()){
                    st.pop();
                }else{
                    set.insert(i);
                }
            }
        }
        
        while(!st.empty()){
            set.insert(st.top());
            st.pop();
        }
        
        string res="";
        for(int i=0;i<s.length();i++){
            if (s[i]!='(' && s[i]!=')'){
                res+=s[i];
            }
            else{
                if (set.count(i) == 0){
                    res+=s[i];
                }
            }
        }
        
        return res;
    }
};