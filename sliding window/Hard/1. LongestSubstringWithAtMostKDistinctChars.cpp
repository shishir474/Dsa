Longest Substring With At Most K Distinct Chars

for(int i = 0; i < n; i++){
    unordered_set<char>  st;
    for(int j = i; j < n ;j++){
        st.insert(s[j]);
        if(st.size() > k){
            // i..(j-1)
            ans = max(ans, j - i);
            break;
        }
    }
}

return ans;
TC: O(n^2)
SC: O(26) -- Im assuming that we are just dealing with A-Z chars


------------------------------------------------------------------------------

unordered_map<char, int> mp;
int max_len = 0;
int l = 0, r = 0;
while(r < n){
    mp[s[r]]++;
    while(mp.size() > k){
        mp[s[l]]--;
        if(mp[s[l]] == 0) mp.erase(s[l]);
        l++;
    }
    max_len = max(max_len, r - l + 1);
    r++;
}

return max_len;

TC: O(2 * n)
SC: O(26) --  Im essentially storing all the chars in my freq mp & in the worst case we might encounter all 26 alphabets. Therby making my space complexity O(26)


------------------------------------------------------------------------------

Most optimal solution: 
    
In order to optimise 2 * n sol. we basically are looking towards O(n) & the way we can acheive this is by getting rid of the inner while loop.
But lets understand why did we neeed the inner while loop in the previous case?
we basically keep on expanding until the mp.size() <= k
The moment size > k, we need to trim down characters from the front. We cannot continue to expand because that will definitely lead to > k distinct characters 

We used to keep on trimming down until the map size > k

Here in this sol, we actually dont need to trim it down until this point. THe reason it works is because 
1. Im not allowing my ans to be updated if mp.size() > k 
2. If mp.size() > k, then we just move the left pointer by 1 step. 


unordered_map<char, int> mp;
int max_len = 0;
int l = 0, r = 0;
while(r < n){
    mp[s[r]]++;
    if(mp.size() > k){
        mp[s[l]]--;
        if(mp[s[l]] == 0) mp.erase(s[l]);
        l++;
    }
    if(mp.size() <= k)
        max_len = max(max_len, r - l + 1);
    r++;
}

return max_len;


TC: O(n)
SC: O(26) --  Im essentially storing all the chars in my freq mp & in the worst case we might encounter all 26 alphabets. Therby making my space complexity O(26)
