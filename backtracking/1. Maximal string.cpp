Maximal String

Medium

221

13
Asked In:
Apple
Problem Description
 
 

Given a string A and integer B, what is maximal lexicographical string that can be made from A if you do atmost B swaps.



Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5



Input Format
First argument is string A.

Second argument is integer B.



Output Format
Return a string, the naswer to the problem.



Example Input
Input 1:

A = "254"
B = 1
Input 2:

A = "254"
B = 2


Example Output
Output 1:

 524
Output 2:

 542


Example Explanation
Explanation 1:

 Swap 2 and 5.
Explanation 2:

Swap 2 and 5 then swap 4 and 2.


void solveUtil(string s, int moves, string& ans){
    if(moves==0){
        if(s.compare(ans) > 0){
            ans = s;
        }
        return;
    }
    
   for(int i=0;i<s.length();i++){
       for(int j=i+1;j<s.length();j++){
           if(s[j] > s[i]){
            swap(s[i],s[j]);
            solveUtil(s,moves-1,ans);
            swap(s[i],s[j]);
           }
           
       }
   }
    
}
string Solution::solve(string A, int B) {
    string ans="";
    solveUtil(A,B,ans);
    return ans;
}
