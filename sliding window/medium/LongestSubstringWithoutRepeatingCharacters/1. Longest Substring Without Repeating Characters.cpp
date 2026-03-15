Longest Substring Without Repeating Characters

Solution
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

// Brute force solution 
explore all substrings and find the longest one with non repeating characters

for(int i =0;i < s.length(); i++){
    vector<int> hash(256,0);            // 256 chars can be present in the string
    for(int j = i; j < s.length(); j++){
        if(hash[s[j]] == 1) break;
        hash[s[j]]++;
        maxLen = max(maxLen, j - i + 1);
    }
}

TC: O(n^2) running 2 nested for loops,
SC: O(256)   for hash array 

we have to optimise this. So we are looking towards O(n) or O(nlogn)

Any problem which involves finding the longest substring , you should straight away start thinking of 2 pointers & a sliding window approach.

It not a specific algo, its rather a constructive algorithm which keeps on changing according to the problem statement. The only think which stays constant is the window, you keep on moving the window.
How you move the window depends on the problem statement 

Ill take 2 ptrs and a hash. In the hash Ill store the freq of the chars. At each instance, Ill check if the right ptr char is present in the hash. If its not I can 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> mp;
     
        int maxLen = 0;
        int i=0,j=0;
        while(j < s.length()){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }    
            maxLen = max(maxLen, j - i + 1);    
            j++;
        }
                
        return maxLen;
    }    
};


-- better solution  Used hash[] instead of mp, to get rid of logarithmic factor  

l
c a d b z a b c d
r

maxLen = 0, l = 0,  r = 0
map<char,int> mp;       // char, last_idx at which the char was seen
I need a hashmap to remember when did I last seen a char 

[l..r] window represents the substring we are looking at 

l
c a d b z a b c d
r

"c" is the substring which Im considreing here. Ill look in to the map and check have I seen 'c' previously. No I havent  
what is the length ? r - l + 1 => 0 - 0 + 1 
maxLen = 0 
len > maxLen => so update the maxLen = 1

l
c a d b z a b c d
  r
This time "ca" is the substring which Im considering. & in order to consider this 'a' shouldnt have appeared previously
len = 1 - 0 + 1 =2 > maxLen 
update maxLen = 2 

l
c a d b z a b c d
    r
"cad" is the substring which Im considering this time & In order to consider d, it shouldnt have appeared previously
len = 2 - 0 + 1 =3 > maxLen 
update maxLen = 3

c  -> 0, a -> 1, d -> 2 

l
c a d b z a b c d
      r

"cadb" is the substring which Im considering this time & In order to consider b,  it shouldnt have appeared previously
len = 3 - 0 + 1 =4 > maxLen 
update maxLen = 4

c  -> 0, a -> 1, d -> 2, b -> 3 

l
c a d b z a b c d
        r 
"cadbz" is the substring which Im considering this time & In order to consider z,  it shouldnt have appeared previously
len = 4 - 0 + 1 =5 > maxLen 
update maxLen = 5

c  -> 0, a -> 1, d -> 2, b -> 3 , z -> 4

l
c a d b z a b c d
          r 
"cadbza" is the substring which Im considering this time & In order to consider a,  it shouldnt have appeared previously
But it has appeared previously, so we bring l = mp['a'] + 1 & update last occurence of 'a' to r

    l
c a d b z a b c d
          r 
c  -> 0, a -> 5, d -> 2, b -> 3 , z -> 4
len = 5 - 2 + 1 =4 not greater than maxLen 

    l
c a d b z a b c d
            r
"dbzab" is the substring which Im considering this time & In order to consider b,  it shouldnt have appeared previously
But it has appeared previously, so we bring l = mp['b'] + 1 

c  -> 0, a -> 5, d -> 2, b -> 6 , z -> 4
        l
c a d b z a b c d
            r

        l
c a d b z a b c d
              r
c  -> 7, a -> 5, d -> 2, b -> 6 , z -> 4

        l
c a d b z a b c d
                r

int maxLen = 0;
int l = 0, r = 0;

// instead of the hash map, Ill use hasharr since we know that we are only dealing with 256 char. Initialised the hasharr with -1, representing each char last index initially is -1
vector<int> hash(256,-1);
while(r < s.length()){ 
    // check if s[r] has been seen previously & is in range [l..r] -> then only consider it to be present
    if(hash[s[r]] != -1 && hash[s[r]] >= l){
        l = hash[s[r]] + 1;
    }
    maxLen = maxLen(max, r - l + 1);
    hash[s[r]] = r;
    r++;
}

TC: O(n)    -- r is looping by 1 step (the while loop is dependent on r)
SC: O(256)