You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].


// Logic: 
We want to construct the string chain
Instead of iterating from j = 0 to i-1 and checking if jth string length is l-1 (assuming ith string length is l) and jth string is a subsequence of ith string(only 1 char extra).
what I can do is for the ith string: I''ll remove one char at a time and check if I have encoutered this string until this point.
I''ll also maintain a map<string,int> where mp[s] = length of the string chain ending at string s 

so, first sort the strings[], so that smaller length strings are processed first.
ans for each index will be atleast 1. 
For each I can start a new chain or it can extend any other previous chain 
I''ll remove one char at a time from strings[i], lets call this string s1 and check if we have encoutered this in map mp. If yes mp[strings[i]] = mp[s1] + 1
There could be multiple s1's. We need to pick the one which has max(mp[s1])


Solution
traversing the array in increasing order is required. so sort the strings on the basis of length
Now for each string we have to check for the string whose length is just 1 less then the curr string length, If that string is a valid string, then dp[i]=max(dp[i], dp[j]+1);
This can be optimised using map
for a string we will process that string , by removing every char one by one(one char at a time) & check if the remaining substring is already precomputed(It will be present in the map)
if(mp.count(rem)==1){
    mp[s] = max(mp[s], m[rem]+1);
}




TC: O(nlogn)+O(n*l) where l is the string lenght

SC: O(n)

CONSTRAINTS
n<=3000
l<=16

struct compare{
    bool operator()(const string &s1, const string &s2){
        // sort the strings in increasing order of their length
        return s1.length() < s2.length();
    }
}
class Solution {
public:
    static bool compare(const string& s1, const string& s2){
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),compare);
        
        int res=0;
        map<string,int> mp;
        
        for(int i=0;i<words.size();i++){
            string s = words[i];
            // for s, find the best value that you have found so far
            int ans=0;
            for(int j=0;j<s.length();j++){
                // Remove one char at a time and check if you have encoutered this string in mp. If yes, update your best_val accordingly
                string t = s.substr(0,j) + s.substr(j+1);
                if (mp.find(t)!=mp.end()){
                    ans = max(ans, mp[t]);
                }
            }

            // finally ans for strings[i] will be 1 + best_val
            mp[s] = 1+ans;
            // insert this into your map
            res = max(res, mp[s]);
        }
        
        return res;
    }
};
