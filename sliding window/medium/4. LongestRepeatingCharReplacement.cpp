int ans = 0;
for(int i  = 0; i < s.length(); i++){
    int mxf = 0;
    unordered_map<char,int> mp;
    for(int j =i; j < s.length(); j++){
        mp[s[j]]++;
        mxf = max(mxf, mp[s[j]]);
        // i..j substr 
        int del = (j - i + 1) - mxf;
        if(del <= k){
            ans = max(ans, j - i + 1);
        }
    }
}

return ans;

    l
A A B A B B A
r r r r r


int characterReplacement(string s, int k) {
    unordered_map<char,int> mp;
    int ans = 0;
    int l = 0, r = 0;
    int mxf = 0;                // stores max freq
    while(r < s.length()){
        mp[s[r]]++;
        mxf = max(mxf, mp[s[r]]);
        int del = (r - l + 1) - mxf;            // we will convert all non max freq char to max freq char 
        // l..r is a valid segment only if del <= k
        while(del > k){ // we will trim down the segment
            mp[s[l]]--;            // remove s[l] -- reduce the freq
            if(mp[s[l]] == 0) mp.erase(s[l]);
            l++;
            // update the mxf -- Ill have to get the maxf from the mp
            mxf = 0;            // made it 0 & then found the maxf in the map
            for(auto it: mp){
                mxf = max(mxf, it.second);
            }
            del = (r - l + 1) - mxf;
        }
    
        ans = max(ans, r - l + 1);
        r++;
    }

    return ans;

}

//  TC: O(2 * n * 26)

Outer while loop starts from 0 and runs till n --- so definitely its going to contribute O(n)
Then there's another while loop which is trimming off l. But you need to understand that it is not everytime going till end of string.
For the first time it might go 2places, then 3places, then 2places . Overall throughout the journey it might go n places.

So can I say the outer while loop is taking O(n) and the inner while loop throughout the journey is taking O(n)
so that is O(n) + O(n) and then the innermost loop which runs for at max 26 times (since mp size at max will be 26)

hence TC: O(n+n)*26

in the worst case the map loop will run 26 times (when the map contains all the uppercase characters)

SC: O(26) -- I cannot optimise this becuase we need to store the freq 


-----------------------------------------------------------------------------

So can I optimse? 
Yes, the current sol is taking O(2 * n) * 26
This O(26) bcz Im rescanning teh map and updating my maxfreq 



How can we optimsise the mp loop?



// Got rid of the inner while loop - used the same concept which we did in MaxConsecutiveOnes3
// Just moved the left ptr once 
int characterReplacement(string s, int k) {
    unordered_map<char,int> mp;
    int ans = 0;
    int l = 0, r = 0;
    int mxf = 0;                // stores max freq
    while(r < s.length()){
        mp[s[r]]++;
        mxf = max(mxf, mp[s[r]]);
        int del = (r - l + 1) - mxf;            // we will convert all non max freq char to max freq char 
        // l..r is a valid segment only if del <= k
        if(del > k){ // we will trim down the segment
            mp[s[l]]--;            // remove s[l] -- reduce the freq
            if(mp[s[l]] == 0) mp.erase(s[l]);
            l++;
            // update the mxf  -- O(26)
            for(auto it: mp){
                mxf = max(mxf, it.second);
            }
            del = (r - l + 1) - mxf;
        }
        if(del <= k)
            ans = max(ans, r - l + 1);
        r++;
    }

    return ans;

}

TC: O(n * 26)



-----------------------------------------------------------------------------

// MOST OPTIMAL SOLUTION                -- watch last 5mins of striver's video
// insane hack which optimises the n * 26 to n.  --- PENDING

Got rid of the map loop. The idea is there's no point in downgrading the maxfreq
just trimming down is sufficient

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int ans = 0;
        int l = 0, r = 0;
        int mxf = 0;                // stores max freq
        while(r < s.length()){
            mp[s[r]]++;
            mxf = max(mxf, mp[s[r]]);
            int del = (r - l + 1) - mxf;            // we will convert all non max freq char to max freq char 
            // l..r is a valid segment only if del <= k
            if(del > k){ // we will trim down the segment
                mp[s[l]]--;            // remove s[l] -- reduce the freq
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
                // just trimming down is sufficient -- there's no point in downgrading the maxfreq
            }
            if(del <= k)
                ans = max(ans, r - l + 1);
            r++;
        }

        return ans;     

    }
};

TC: O(n)
SC: O(26)