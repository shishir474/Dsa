Expression contains redundant bracket or not [AMAZON]

Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant, else ‘No’.
Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.
Example: 
 

Input: 
((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No

Explanation:
1. ((a+b)) can reduced to (a+b), this Redundant
2. (a+(b)/c) can reduced to (a+b/c) because b is
surrounded by () which is redundant.
3. (a+b*(c-d)) doesnt have any redundant or multiple
brackets.
 
LOGIC: 

push opening and operators in the stack. On encoutering closing bracket if st.top() is '(' => this pair of brackets are redundent -> return true
else pop krte jao jab tak st.top()!='('
pop one more time to remove the '('
NOte: since it is given that the string is balanced it is sure that there will always be an opening bracket for every closing bracket

TC:O(n), SC:O(n)


int Solution::braces(string s) {
     stack<char> st;
   bool isredundent = false;
   for (int i=0;i<s.length();i++){
       if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
           st.push(s[i]);
       }
       else if(s[i] == '('){
           st.push(s[i]);
       }
       else if(s[i]==')'){
           if (st.top()=='('){
               isredundent=  true;
               break;
           }
           
           while(!st.empty() && st.top()!='(')
           st.pop();
           
           if (!st.empty())
           st.pop();
           
       }
   }
   
   return isredundent;