Interleaving Strings

Hard

156

6
Asked In:
Google
Yahoo
Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.
    
    bool check(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3,    unordered_map<string, bool>& mp)
    {
        // base case
        if (p3 == len3)
        {
            return (p1 == len1 && p2 ==  len2) ? true : false;
        }
        
        string key = to_string(p1) + "-" + to_string(p2) + "-" + to_string(p3);
        if (mp.find(key)!=mp.end())
            return mp[key];
        
        bool ans;
        // key is not present so we need to calculate ans. There are 3 cases
        //case 1:
        if (p1 == len1)
        {
       ans = (s2[p2] == s3[p3]) ? check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1,mp) : false; 
            mp[key] = ans;
            return ans;
        }
        else if(p2 == len2)
        { // case 2
     ans = (s1[p1] == s3[p3]) ? check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1,mp) : false; 
            mp[key] = ans;
            return ans;
        }
        else
        {
            // case 3
            bool one = false, two = false;
            if (s1[p1] == s3[p3])
            {
                one = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1,mp);
            }
            if (s2[p2] == s3[p3])
            {
                two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1,mp);
            }
            mp[key] = one || two;
            return mp[key];
            
        }
        
        
}
int Solution::isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        if (len1+len2 != len3) return false;
          
         unordered_map<string, bool> mp;
        return check(s1,s2,s3,len1,len2,len3,0,0,0,mp);
}
