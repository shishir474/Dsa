Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.


class Solution {
public:
    // https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/779928/Simple-O(n)-stack-solution-with-detailed-explanation
    
    
    
//     Brief Idea: Maintain a stack. Every time we see a ( we need to have 2 ) to balance. So we would push 2 to the stack. Then when we see ) we would check the top of the stack. If the top is 2, that means this is the first ) that will match the previous (. So we would change the top to 1. In case the top of stack had 1 it means we are seeing the second ) for some ( and so we just pop this 1 from the stack.

// Details of transition:

// When we see (:
             
// And the stack is empty or has a 2 at the top: we just push another 2.
             
// And the stack had 1 at the top: This means we have just seen () and now we are seeing (. In this case, we need to first provide a ) to the previous ( and then we can process the current (. So increment the answer, pop the 1 (which was for last () and push a 2 (for current ().


// When we see ):

// And the stack is empty: We have encountered a lone ). We would need to add ( to the sequence to balance, which would match one of its ) with the current ). So we increment the answer. Moreover, it would also need another ) to match. So we push 1 to the top. This is like saying we have seen () (of which ( was inserted by us).

// And the stack had 1 at the top: This the second ) for some (. We just pop from the stack.
                                                            
// And the stack had 2 at the top: This the first ) for some (. We just pop 2 from the stack and push 1.
                                                           
// At the end of going through the string we just add up all the numbers in stack, which represents the number of ) we need to balance.
             
             
    int minInsertions(string s) {
            int ans = 0;
        stack<int> t;
        for (char c : s) {
            if (c == '(') {
                if (t.empty() || t.top() == 2) t.push(2);
                else {
                    t.pop();
                    t.push(2);
                    ans++;
                }
            }
            else {
                if (t.empty()) {
                    t.push(1); ans++;
                } else if (t.top() == 1) {
                    t.pop();
                } else if (t.top() == 2) {
                    t.pop(); t.push(1);
                }
            }
        }
        while (!t.empty()) {
            ans += t.top();
            t.pop();
        }
        return ans;
    }
};