Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701

class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            ans+=pow(26,n-i-1)*(s[i]-'A'+1);
        }
        return ans;
    }
};


// Reverse of this questions i.e given n find the corresponding string
Example: 
n = 700
The remainder (n%26) is 24. So we put ‘X’ in the output string and n becomes n/26 which is 26. 
Remainder (26%26) is 0. So we put ‘Z’ in the output string and n becomes n/26 -1 which is 0.


    string colName (long long int n)
    {
        string ans="";
        while(n){
            int rem=n%26;
            if(rem==0){
                ans+="Z";
                n = (n/26) - 1;
            }else{
                ans.push_back('A'+rem-1);
                n/=26;
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }