You will be given 2 strings s and t. You have to return the length of the min length substring in s which has all the characters of t with its frequency in it.

s = "ddaaabbca"
t = "abc"

You know what a substring is? Any contiguous portion of the string.


Brute Force:
Consider every substrings -- should have length atleast t.length()

unordered_map<char,int> mpt;
for(auto c: t) mpt[c]++;

for(int i = 0; i < s.length(); i++){
    unordered_map<char,int> mp;
    for(int j = i; j < s.length(); j++){
        // [i..j] substring 
        mp[s[j]]++;
        if(j - i + 1 >= t.length()){
            int f = 0;
            for(auto c: mpt){
                if(mpt[c] > mp[c]) {f = 1; break;}
            }
            if(f == 0){     // This could be 1 possible substring -- we have to find the shortest string 
                len = min(len, j - i + 1);
            }
        }
    }
}

TC: O(n * n * m)