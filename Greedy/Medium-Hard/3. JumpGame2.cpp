Same as previous problem -- here we just have to figure out the minimum no of jumps required to reach n-1 th index.

NOTE: It is stated in the problem statement that you can always reach the end of the array. 

What''s the extreme naive solution that I can think off: I am at the 0th index and there nums[0] possible ways 
You can try out all the possibilities -- recursion

can I try out all ways? yes I can & then I can pick the minimum of all of them
[2, 3, 1, 4, 1, 1, 1, 2]

f(idx, jumps){
    if(idx >= n-1) return jumps; 

    int mini = INT_MAX;
    for(int i = 1; i<= arr[idx]; i++){      // just make sure you dont start i with 0, then you will go to the same index
        mini = min(mini, f(idx + i, jumps + 1));
    }

    return mini;
}
This will be the recursive code & If I have to write down the TC
TC: N^N This is going to be exponential in nature. You are going for n indexes, assuming all the jumps are at n or somewhere near that. It can go exponential in nature.
SC: I''ll be using auxilary stack space of O(N)

This can be optimised :

adding memoisation 

f(idx, jumps){
    if(idx >= n-1) return jumps; 
    if(dp[idx][jumps] != -1) return dp[idx][jumps];

    int mini = INT_MAX;
    for(int i = 1; i<= arr[idx]; i++){      // just make sure you dont start i with 0, then you will go to the same index
        mini = min(mini, f(idx + i, jumps + 1));
    }

    return dp[idx][jumps] = mini;
}

TC: The time complexity will now become O(n^2)
SC: O(n^2) + O(n) // N^2 for dp matrix and n for auxilary stack space 

If we write a top down code -- we can get rid of the auxilary stack space, but my TC still gonna be n^2


---------------------------
Futher optimising the TC -- If we have to optimise the TC and we are currently at n^2 --> then that mean we have to go somewhere around O(N)


How should I think of a O(N) solution?
What was I doing in the recursion? I was trying out all possible ways and then I took the minimum.

         0. 1. 2. 3. 4. 5. 6. 7   
arr[] = [2, 3, 1, 4, 1, 1, 1, 2]
Can I try out all possible ways without recursion? May be I can. I''m standing at the 0th index. If I take a jump from here 
I can either reach 3 or 1  

Now we're dealing with ranges 
[2, 3, 1, 4, 1, 1, 1, 2]
||  |  |  |  |  |     |  
--  ----  ----  -------
0    1     2     3
From 3, I can go to 1 & 4. There is no point in reaching 1 because that will require 2 jumps 2->3->1
Instead 2->1 can be done in 1 Jump 

Once you reach the last index -- you stop & the last range is reachable at 3 jumps

--------------------------------------------------------------
    NOTE: l will go 1 place ahead of r i.e l = r + 1
    r will go to farthest i.e r = farthest
    First I''ll update l and then I''ll update r
--------------------------------------------------------------

Already did a similar problem -- valid parenthesis string 
We optimised the recursion in 2 ways



lets approach this problem in the reverse direction (this solution is basically derived from recursion sol -- optimiesed it using memoisation -- further optimised by writing iterative code (this gets rid of auxilary stack space) )

***** 4 solutions in total
1. Recursive Solution   -- TC: N^N This is going to be exponential in nature. You are going for n indexes, assuming all the jumps are at n or somewhere near that. It can go exponential in nature.
                           SC: auxilary stack space of O(N)
2. Recursive + Memoisation   TC: O(n * max(nums[i])) -- quadratic SC: O(n^2) + O(n)
3. Iterative -- TC: quadratic 
4. Ranges -- TC: O(n), SC: O(1)

arr[] = {2, 3, 1, 1, 4}

I have created a jump[] where jumps[i] stores the min jumps required from ith index to reach n-1th index 
int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> jumps(n);
        jumps[n-1] = 0;      // no jump required from this point -- you're already at the last index 

        for(int i = n-2; i>=0; i--){
            if(nums[i] == 0) {jumps[i] = INT_MAX; continue;}    // you wont be able to reach from this point -- hence storing INT_MAX
            int mn = INT_MAX;
            for(int j = i + 1; j <= min(n-1, i + nums[i]); j++){
                mn = min(mn, jumps[j]);
            }
            jumps[i] = (mn == INT_MAX)? INT_MAX : 1 + mn; // you wont be able to reach from this point -- hence storing INT_MAX
        }

        return jumps[0];
    }

TC: O(n * max(nums[i])); -- quadratic solution (same as the DP one)
SC: O(n)


-- 
Can we do this in constant space and without using the inner for loop.

I''m initially standing at 0th index -- l,r = [0,0] is my current range/window
Now if I travel within my current window from l to r and find the farthest that I can go from this window 
Update 
    l = r + 1       (l will move to r + 1 -- this will starting point of my next window)
    r = farthest    (this will be the end point of my next window)

0     1.    2.    3.    4
2     3.    1.    1.    4
<->

l = r = 0
farhtest = 0 + 2 = 2;
jumps = 0

l = r + 1 = 1
r = farthest = 2

0     1.    2.    3.    4
2     3.    1.    1.    4
<->.  <----->

l = 1
r = 2 
farthest = max(1+3, 2+1) = 4
jumps = 1

0     1.    2.    3.    4
2     3.    1.    1.    4
<->.  <----->     <----->

l = r + 1 = 3
r = farthest = 4 
since r >= n-1 : we return jumps  = 2;

** IMP: ** 
we run the loop until r < n-1
The moment r >= n-1: return jumps

int l = r = 0;
int jumps = 0;

// If r goes at n-1 or exceeds n-1 I stop
while(r < n - 1){
    int farthest = 0;
    // figuring out what is the farthest I can go for this range [l,r]
    for(int k = l; k<=r; k++){
        farthest = max(farthest, k + arr[k]);
    }

    // once you have traversed all the elements in [l,r] --> we know the new range 
    l = r + 1;
    r = farthest;
    jumps++;
}    

return jumps;


*****************************************
TC: O(n)    -- From the naked eye it looks like we are running 2 loops, but in actual each element is being traversed only once.
So what we are doing at the end of the day is traversing each element one by one. The outer while loop is just to check -- did you reach ?
So eventually the TC is O(N) which is linear in nature.

SC: O(1)    -- Not using any extra space, just a couple of variables
*****************************************


NOTE: This is a classic technique which is used to determine the range within our reach. 
Initially our reach was only from [0,0]. Then by traversing in this range we figured out the end point of our next range 
which is [1,2]. Start of a range is always going to be prev r + 1. This is something which is fixed, but r is something which we need to calculate by traversing in the previous range & figure out the max.  


*****************************************
-- We started with a recursive solution. Then converted the recursive based solution to a range based solution. 
WHy this problem is classified under Greedy algorithm? Because we are trying to reach the farthest within a particular range
*****************************************