Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.


SOLUTION:
The idea is to first remove all balanced part of expression. For example, convert “}{{}}{{{” to “}{{{” by 
removing highlighted part. If we take a closer look, we can notice that, after removing balanced part, 
we always end up with an expression of the form }}…}{{…{, an expression that contains 0 or more number 
of closing brackets followed by 0 or more numbers of opening brackets. 
How many minimum reversals are required for an expression of the form “}}..}{{..{” ?. Let m be the total 
number of closing brackets and n be the number of opening brackets. We need ⌈m/2⌉ + ⌈n/2⌉ reversals. For 
example }}}}{{ requires 2+1 reversals.


int countRev (string s)
{
    // your code here
    if (s.length()%2) return -1; // odd length can't be balanced
    
    int open=0,closed=0; // no. of unbalanced opening and closing brackets
    for(int i=0;i<s.length();i++){
        if(s[i]=='{') open++;
        else{
            if(open>0) open--;
            else closed++;
        }
    }
    
    return ceil(open/2.0) + ceil(closed/2.0);
}

// same logic can be implemented using one variable alsp
int temp=0,ans=0;
for(int i=0;i<s.length();i++){
    if (s[i]=='{') temp++;
    else{
        if(temp > 0) temp--;
        else {
            temp++; ans++;
        }
    }
}

ans+=(temp/2);
return ans;