You are given a bunch of strings. wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.




struct compare{ // sort the strings in increasing order of their lengths
    bool operator()(const string &s1, const string &s2){
        return s1.length() < s2.length();
    }
};

class Solution {
public:
    bool isPredecessor(string s1, string s2){
        // return true if s1 is a predecessor of s2
        if(s1.length() + 1 != s2.length()) return false;

        for(int i = 0; i < s2.length(); i++){
            string temp = s2.substr(0,i) + s2.substr(i+1); // exclude the ith char
            if(temp.compare(s1) == 0)   // s1.compare(s2) == 0 means s1 is equivalent to s2
                return true;
        }
        return false;
    }

    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), compare());
        
        int n = words.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPredecessor(words[j], words[i]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};

// TC : O(nlogn + n * n * maxWordLen)
// SC: O(1)

------------------------------------------------------------------------------------------------------------------------

The time complexity can be optimised. Instead of checking every previous string if it is a potential predecessor, 
I can remove one char at a time from the current string and check if the ans for the resulting string is already computed using hashmap 
This is just a hack in this kinda problems (not necessary to do this always which means the above solution is also acceptable as it is more intuitive)

If you solve this question thinking of subsequences -- you cannot sort because the order will change 
But here the problem statement states to find the longest sequence (they dont care about the order/subsequence, you can pick up from anywhere), thus sorting to form the longest possible sequence makes sense 
So essentially it is a subset, instead of subsequence. And in the subset you can just sort (because nobody cares about the order of eleements in the subset)


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](const string &s1, const string &s2){
            return s1.length() < s2.length();
        });     // sorting is crucial to ensure that shorter string appear in the inital portion of the array
        
        int n = words.size();
        unordered_map<string,int> mp;

        int maxi = 1;
        for(auto word: words){
            mp[word] = 1;
            for(int j = 0; j < word.length(); j++){
                string temp = word.substr(0,j) + word.substr(j+1);
                if(mp.count(temp)){
                    mp[word] = max(mp[word], 1 + mp[temp]);
                }
            }
            maxi = max(maxi, mp[word]);
        }

        return maxi;
    }
};

// TC: O(n * wordLen)
// SC: O(n)