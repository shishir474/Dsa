2002. Maximum Product of the Length of Two Palindromic Subsequences
Medium

Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.

Input: s = "leetcodecom"
Output: 9
Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
The product of their lengths is: 3 * 3 = 9.

constraints: s.length()<=12

// Since the constraints are low, we will find all the subsequences using mask and store all the palindromic subs in a vector along with their mask
// 2 subs are disjoint if & operation between their masks is 0
// i.e assume string s1 and s2 has mask m1 and m2 respecitvely. If m1&m2 == 0, then s1 and s2 are disjoint



soltuion;
1. we can check if 2 subsequences are dijoint or not using mask. let s1 and s2 be 2     subseqeuences of string s and m1 and m2 be their corresponding masks, then s1 and s2 are disjoint iff m1&m2 == 0

2. genrate all subsequences, check which of them are palindrome and if its palindrome then store it and its corresponding mask(which will be used later) into a vector

3 vector contains all the palindromic subsequences. consider every pair of strings in the vector, check if they are disjoint and iff yes, than update ans iff possible


class Solution {
public:
    string getString(int mask,string s){
        string ans="";
        for(int i=0;i<31;i++){
            if(mask&(1<<i)){
                ans.push_back(s[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    bool isPalindrome(string s){
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i]) return false;
        }
        return true;
    }

    int maxProduct(string s) {
        int n=s.length();
        vector<pair<string,int> > v;
        
        // Generate all subseuquences
        for(int mask=1;mask<(1<<n);mask++){
            string temp=getString(mask,s);
            if(isPalindrome(temp)){
                v.push_back({temp,mask});
            }
        }
        
        int ans=0;
        
        // 
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                string s1=v[i].first, s2=v[j].first;
                int mask1=v[i].second, mask2=v[j].second;
                int n1=s1.length(), n2=s2.length();
                // if these subs are disjoint
                if((mask1&mask2) == 0){
                    ans = max(ans,n1*n2);
                }
            }
        }
        
        return ans;
        
    }
};

// TC: O(n * 2^n) for generating all subs and checking if they are palindrome
// SC: O(2^N) for storing all the subs


Follow UP:
1960. Maximum Product of the Length of Two Palindromic Substrings
Hard                -- USES Manacher Algorithm (need to see how this works PENDING)