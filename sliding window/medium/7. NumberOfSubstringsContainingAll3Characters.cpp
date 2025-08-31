Number of substrings containing all the 3 characters a,b,c 


s = "bbacba"
bbac
bbacb
bbacba
bac 
bacb
bacba
acb
acba
cba

count the total no of substring that contains atleast 1 occcurence of each char a,b, and 

brute force:

Whats the extreme naive sol that I can think off? Try out all the substrings

for(int i = 0; i < n; i++){
    vector<int> hash(3,0);          // can keep a hash[] of size 3 since we only have 3 chars
    for(int j = i; j < n;j ++){
        hash[s[j] - 'a']++;             // s[j] - 'a' : subtract 'a', so that 'a' resembles to 0, 'b' resembles to 1 & 'c' resembles to 2
        // once we have atleast  1 occurence of each char 
        if(hash[0] > 0 and hash[1] > 0 and hash[2] > 0){
            cnt += (n - j); break;
        }
    }
}

TC: O(n^2) -- near about n^2, not exact 
SC: O(1)

The extreme brute forces would be to do cnt++; and check for all substring.

But using this trick cnt += (n - j), we've essentially accounted all the substrings with the prefix[i..j] & since this prefix has atleast 1 occurence of each char,
Ive considered all the substrings that can be formed with this prefix and that is why we break out. Becoz we know that we have considered all the substring for i 
and we can easily move to next i 

for i = 0, at bbac, we got to know that we have atleast 1 occurence of each char. Do  I need to traverse any further?
No I dont I just can add the no of substring with bbac as the prefix and that will n - j which is 6 - 3 = 3
bbac
bbacb
bbacba


This is the slight optimisation which we did. Will that improve the TC? Yes, for certain test cases, but not for the worst 

imagine a string like 'aaaaaaabc' youll still traverse till the end, right. Becoz you dont have any valid combination where this break will execute.

It is a subtle optimisation which we did, and this is what we'll use in the most optimal sol as well.

---------------------------------------------------------------------------------------------

Optimal SOLUTION

So Im looking to optimise my prev sol, which was taking n^2. That means we are looking to go towards the direction of O(n)
The problem has substrings & in order to do this O(n) -- we;ll have to use 2ptrs & sliding window 

I know one thing, with every index, there are a bunch of substrings which start. But we'll do the reverse.
With every char, there are a bunch of substrings that ends.

We can do this from the front as well, but in order to get a frontward implementation -- we'll focus on the substrings that are ending at the ith index.

     012345  
s = "bbacba"

If you''re standing at 'b' 4th index, what is the minimal length of the substring that has all 3 chars "acb" i.e [2..4]

So if we are considering 4th index(ending point), minimal length of the window that has all 3 chars is 3. This is one substring
How many more susbstring can I have? I cannot add at the front. But I can add in the back. Overall I can get 3 substrings ending at this index which has all 3 chars

acb -- [2..4]
bacb
bbacb

cnt += (2 + 1)

So for every char, Ill try to figure out the minimum window. If I can figure out the minimum window, then I can get the cnt of substring ending at that index

Il;l take a hashmap and track the last seen index 
last seen :      a = -1, b = -1, c = -1

l
012345
bbacba      last seen :      a = -1, b = 0, c = -1
r

I dont have a and c yet, so Ill move ahead 

l
012345
bbacba      last seen :      a = -1, b = 1, c = -1
 r

I dont have a and c yet, so Ill move ahead 

l
012345
bbacba      last seen :      a = 2, b = 1, c = -1
  r

I dont have c yet, so Ill move ahead 

l
012345
bbacba      last seen :      a = 2, b = 1, c = 3
   r
I have all 3 chars -- the no of substring that I can get here  - min(hash[a], hash[b], hash[c]) = 1
// 1..3 is the minimum length window that has all the 3 chars 
cnt += (1 + 1)

l
012345
bbacba      last seen :      a = 2, b = 4, c = 3
    r
I have all 3 chars -- the no of substring that I can get here  - min(hash[a], hash[b], hash[c]) = 2
// 2..4 is the minimum length window that has all the 3 chars 
cnt += (2 + 1)

l
012345
bbacba      last seen :      a = 5, b = 4, c = 3
     r
I have all 3 chars -- the no of substring that I can get here  - min(hash[a], hash[b], hash[c]) = 3
// 3..5 is the minimum length window that has all the 3 chars 
cnt += (3 + 1)

vector<int> hash(3, -1);        // track the last seen index
int cnt = 0;
int l =0, r = 0;
while(r < n){
    hash[s[r] - 'a'] = r;
    if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
        int mn = min(hash[0], hash[1], hash[2]);
        cnt += (mn + 1);
    }
    r++;
}

return cnt;

TC: O(n) - just one single while loop which starts from the begin and runs till the end 
SC: O(3) which is as good as constant O(1)

The idea is to figure out the min possible window for each index that has all 3 char. Once we know the min window, we can add on every char to the left of the window to form a new substring 

we could also do -- at every index, what is the min length window on the right . For that I;ll have to traverse from the right 


My optimised sol:
More generic sol -- works when you have got more than 3 char 

Expand until you have got all the required chars. 
add the substrings to cnt => cnt += (n - r)
(n - r) is the total no of substrings which the prefix [l..r]
Start shrinking from the left until you have all the required char -- again add (n -r) to the cnt 

unordered_map<char,int> mp;
int cnt = 0;
int l = 0, r = 0;
while(r < n){
    mp[s[r]]++;
    while(mp.size() == 3){
        cnt += (n - r);
        mp[s[l]]--;
        if(mp[s[l]] == 0) mp.erase(s[l]);
        l++;
    }
    r++;
}

return cnt;

TC: O(2 * n)
    the outer loop runs n times, and the inner loop runs n throughout the entire journey of the outer loop, not for each instance. Hence n + n
SC: O(3) which is as good as O(1)