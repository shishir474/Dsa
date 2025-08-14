002. Maximum Product of the Length of Two Palindromic Subsequences

Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.


Example 1:

Input: s = "leetcodecom"
Output: 9
Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
The product of their lengths is: 3 * 3 = 9.
Example 2:

Input: s = "bb"
Output: 1
Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
The product of their lengths is: 1 * 1 = 1.
Example 3:

Input: s = "accbcaxxcxx"
Output: 25
Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
The product of their lengths is: 5 * 5 = 25.
 

Constraints:

2 <= s.length <= 12
s consists of lowercase English letters only.



Intuition

Since the constraints are low
Generate and store all the palindromic subsequences of s

You can generate all subsequences, using mask from 1 to (1<<n)-1
and then check if the generated subsequence is a palindrome or not
Then store the palindromic subsequences in a vector
Then we can iterate through all pairs of palindromic subsequences and check if they are disjoint or not
if mask1 & mask2 == 0, the 2 subsequences are disjoint
and we can update ans as max(ans, len1 * len2)


class Solution {
public:

    string getString(string s, int mask){
        // get the string corresponding to this mask from s
        string res = "";

        // mask and string s indexes run in the opposite directions of each other
        for(int i=0; i<32; i++){
            // if the ith char is set
            if(mask & (1<<i)){
                res.push_back(s[i]);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool isPali(string s){
        int i = 0, j = s.length()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }


    int maxProduct(string s) {
        
        int n = s.length();
        vector<pair<string,int>> v;     // to store {string, corresponding mask}

        for(int mask = 1; mask < (1<<n); mask++) {
            // get all subs one by one by checking the set bits in mask 
            string subs = getString(s, mask);
            if(isPali(subs)){
                cout<<subs<<endl;
                v.push_back({subs,mask});
            }
        }


        int ans = 0;

        // v contain all the palindromic subs that are present in s
        for(int i=0;i<v.size();i++){
            for(int j=i+1; j<v.size(); j++){
                int mask1 = v[i].second;
                int mask2 = v[j].second; 
                int len1 = v[i].first.length();
                int len2 = v[j].first.length();
                if((mask1 & mask2)  == 0){ // both strings are disjoint
                    ans = max(ans, len1 * len2);
                }
            }
        }

        return ans;


    }
};

