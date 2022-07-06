Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".





Brute force solution:
sol1. consider every substring and check if its valid or not. O(n^2) for considering every substring and O(n) to check if that substring is valid or not. SO TC: O(n^3) sc : O(1);




sol2. TC; O(N) and SC:O(N);

int longestValidParentheses(string s) {
    int ans=0;
    stack<int> st;
    st.push(-1);
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(i);
        else{
            st.pop();
            if(st.empty()) st.push(i);
            else{
                int len=i-st.top();
                ans = max(ans,len);
            }
        }
    }
    
    return ans;
}






constant space solution
sol3 TC:O(n) and sc; O(1);

2 scans required. consider this case ((()). here ans is calculated when traversed in reverse direction.

when iterating from left 
take left=0 and right=0;
if(left==right) -> found a valid substring and its length is 2*left. update maxlen if need to
But if at any point right > left. reset left=right=0


when iterating from right 
take left=0 and right=0;
if(left==right) -> found a valid substring and its length is 2*right. update maxlen if need to
But if at any point left > right. reset left=right=0


int longestValidParentheses(string s) {
    int left = 0, right = 0, maxlength = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = Math.max(maxlength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }

    left = right = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s.charAt(i) == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = Math.max(maxlength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxlength;
}