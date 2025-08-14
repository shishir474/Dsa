1930. Unique Length-3 Palindromic Subsequences

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".


Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")



Constraints:

3 <= s.length <= 10^5
s consists of only lowercase English letters.



class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // calculate the first and last positions of each char
        map<char,pair<int,int>> mp;

        // O(N) loop to construct the mp
        for(int i=0; i < s.length(); i++){
            char c = s[i];
            // if encoutering this char for first time
            if(mp.count(c) == 0){
                mp[c] = {i,i};      // setting it's first and last occurence
            }
            else{       // have already encoutered this char, update it's last occurence 
                mp[c].second = i;
            }
        }

        // find the first and last occurence of each char.
        // if first and last occurence are not same, then the freq is atleast 2 else it is one 
        // if the freq of the char is atleast 2(they can be used as the endpoints of my palindromic subsequence) - now what char can be used in the center (we are only intereseted in length 3 paldindromes)
        // count the # of unique chars between the first and last occurence (only these char can be used as potential centers)
        // char before the first occurence and after the last occurence cannot be used as centers (the string will not be a palindrome)

        unordered_set<char> set;        // to track the # of unique chars between 2 positions

        int count = 0;        // counter variable to track # of unique 3 length palindromic subs

        for(auto it: mp){
            pair<int,int> p = it.second;
            if(p.first != p.second){    // char's freq is atleast 2, can be used as endpoints of my palindromic subs
                // count the no of unique chars b/w its first and last occurence
                set.clear();
                for(int i = p.first + 1 ; i <= p.second - 1; i++){
                    set.insert(s[i]);
                }
                
                count += set.size();          // set.size() unqieu char found between the first and last occurence of it.first -- this many unique 3 length palindromes can be considered
            
            }
        }

        return count;


    }
};

