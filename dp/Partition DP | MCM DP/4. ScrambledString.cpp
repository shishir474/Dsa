Scrambled string 

a = "great"
b = "rgeat"
o/p : true

k = i to j-1
s[i..k] and s[(k+1)..j]

base case: 
if (s1.compare(s2)) == 0:
    return true;

It is guaranted that length of both s1 and s2 is same

for(int k = i; k < j; k++){
    string s1_left = s1[i..k] = s1.substr(i, k-i+1);
    string s1_right = s1[(k+1)..j] = s1.substr(k+1);
    string s2_left = s2[i..k] = s2.substr(i, k-i+1);
    string s2_right = s2[k+1..j] = s2.substr(k+1);
    string s2_prefix = s2.substr(i, j - k);
    string s2_suffix = s2.substr(n - (k - i + 1));

    bool first = solve(s1_left, s2_left) and solve(s1_right, s2_right);
    bool second = solve(s1_left, s2_suffix) and solve(s1_right, s2_prefix);
    if (first or second) return true;
}


class Solution {
public:
    unordered_map<pair<string,string>, bool> memo;

    bool solve(string s1, string s2){
        if(s1.compare(s2) == 0) return true;
        // adding memoisation
        if(memo.count({s1, s2})) return memo[{s1, s2}];
        
        int n = s1.length(), i = 0, j = n - 1;
        for(int k = i; k < j; k++){
            string s1_left = s1.substr(i, k - i + 1);
            string s1_right = s1.substr(k + 1);
            string s2_left = s2.substr(i, k - i + 1);
            string s2_right = s2.substr(k + 1, j - k);
            string s2_prefix = s2.substr(i, j - k);
            string s2_suffix = s2.substr(n - (k - i + 1));

            bool first = solve(s1_left, s2_left) and solve(s1_right, s2_right);
            bool second = solve(s1_left, s2_suffix) and solve(s1_right, s2_prefix);
            if (first or second) return memo[{s1, s2}] = true;
        }
        
        return memo[{s1, s2}] = false;

    }

    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int n = s1.length();
        memo.clear();
        return solve(s1, s2);
    }
};


Time complexity Explaination:
The only thing which we know at this point is that the time complexity of this code is less than 2^n.
We're not able to calculate the exact complexity of this code yet!

Another way to look at this is that the number of unique pairs of strings (s1, s2) that we can form is O(n^2) because both strings can be of length n and we can have n^2 pairs of substrings.
For each pair of substring, we're trying all possible partition points which is O(N)
so that makes this O(N^3) 

Space complexity:
There will be atmost n^2 possible substring pairs, that we'll store in our memoization map.
So the space complexity is O(n^2).
