Scramble String

Hard

247

7
Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.



Given two strings A and B of the same length, determine if B is a scrambled string of S.



Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= len(A), len(B) <= 50
Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
    0

map<pair<string,string>, int> mp;

int solve(string s1, string s2){
    if (s1.compare(s2) == 0) return 1;
    if (mp.count({s1,s2})) return mp[{s1,s2}];

    int n = s1.length();
    
    int ans=0;

    for(int k=0;k<n-1;k++){
        string l1 = s1.substr(0,k+1);
        string r1 = s1.substr(k+1);
        string l2 = s2.substr(0,k+1);
        string r2 = s2.substr(k+1);

        if (solve(l1,l2) and solve(r1,r2)){
            ans = 1; break;
        }
        else if (solve(s1.substr(0,k+1), s2.substr(n-(k+1))) and  solve(s1.substr(k+1), s2.substr(0,n-(k+1)))  ){
            ans = 1; break;
        }
    }

    mp[{s1,s2}] = ans;
    return ans;
}
int Solution::isScramble(const string A, const string B) {
    if (A.length() != B.length()) return 0;
    if (A.length()==0 and B.length()==0) return 1;

    return solve(A,B);
}
