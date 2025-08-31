Given a binary arr, you have to find the no of subarrays whose sum is target 


Brute force:

// check all possible subarrays
int cnt = 0;
for(int i = 0; i < n; i++){
    int sum = 0;
    for(int j = i; j < n; j++){
        sum += arr[j];      /// i..j sum
        if(sum == target) cnt++;
        else if(sum > target) break;
    }
}
TC: O(n ^ 2) -- the outer loop runs n times from start till the end, inner loop does runs somewhere around n (not always)
Hence the tc is somewhere around n^2 and not exactly n^2 

SC: O(1)


----------------------------------------------------------------------------------------

Better sol 


This problem can be trimmed down to -- count subarray sum equals k 
here the arr contained [+,-] elements. 
--- we already did this in arrays playlist (brute, better) and the most optimal sol was using hashing.

This is the hashing based sol where we check at each index the #of prefixes with sum p - goal where p is the prefix sum [0..i]
Plus we also check if the current prefix''s [0..i] sum == goal 

This solution works in all cases if you have +ves, -ves, and zeroes.

// Sol2 Using hashing and 
int n = arr.size();
int ps = 0, cnt = 0;        // prefix sum
unordered_map<int, int> mp; // ps, freq
for(int i = 0; i < n; i++){
    ps += arr[i];
    // # of prefixes with ps-goal sum
    cnt += mp[ps - goal];
    // current prefix
    if(ps == goal) cnt++;
    mp[ps]++;
}

return cnt;

USING Hashing
TC: O(n) -- Again, Im assuming that the map works in O(1), hence O(N). If you assume that the mp takes logarighmic of n, you can add that as well 
SC: O(N)


This solution will also work for this problem statement. But over here we are mentioned that it just contain binary nos, so we can further optimise this.
The only reason is we are given a special condition that the arr contains only +ves and zeroes 

and If im looking to optimise, TC: O(n) and SC: O(n). I definitely cannot optimise the time O(N). But we definitely can optimise the space.
I have n elements, so I cannot optimise time, thats for sure. So the only way I can optimise this is by optimising the space.

Can I get rid of the external map that I was using?
We;ll have to get rid of that map data structure. This is where the optimisation will happen.

SO Im looking at TC of O(N) and SC: O(1) & the problem is involving subarrays. And if Im not using external data structures, 2ptr & sliding window algo comes to my brain.

Whatever problem we did till now, were finding the longest subarray/substring. Over here its slightly different.
Here we have to count the no of subarrays with given sum.

----------------------------------------------------------------------------------------------------


Optimal Solution


How can I do it?
First lets try to analyse how the sliding window works and see if at all can we solve this using sliding window or 2ptrs.

lets take an ex where arr is something like 
l
[1 0 0 1 1 0] and goal = 2
r
We take l and r & we make it stand at the first place.
We are looking at the sum of the segment and count of subarrays. so lets initiallly have it as 0.

sum = 0, cnt = 0

SO initially Im standing at 0th index & [0,0] is the segment. Can I take this no and add it to the sum? Yes I can 
sum = 1
Once I have added it to the sum, is that equivalent to the goal? Its not;
What I can do is, I can take this r and move forward

l
[1 0 0 1 1 0] and goal = 2
   r
The moment I move it forward, I get a 0, sum doesnt change. again move the r 

l
[1 0 0 1 1 0] and goal = 2
     r
again the segment''s sum is not equivalent to goal. so we move forward r

l
[1 0 0 1 1 0] and goal = 2
       r
sum = 2 and is equivalent to the goal. So this is definitely one of the subarrays . Can I count this? yes I can.
So once I have counted this. Ill move r forward 

cnt = 1

l
[1 0 0 1 1 0] and goal = 2
         r
sum = 3
sum is not equivalent to the goal and has exceeded the goal. Thereby if you keep on adding nos in the window, the sum will increase 
You have to decrease the sum, because the sum has exceeded the goal. If I have to decrease, Ill have to eliminiate nos from the left.
Ill have to shrink the window. If Im shrinking the window, the first element that Ill remove is l i.,e 0th index 

So If I remove this 1, the sum will again shrink back to 2 & the l will be at 1st index
This is where Ill say is this valid segment? Yes it is. Can I count this? Yes definitely I can. So Ill cnt this one 

Now ideally what Ill do is Ill take the r and move ahead. If I do this, what happens is, you did consider [1..4] segment , but you could have also considered [2..4] & [3..4] segment
but you didnt becuase we moved the r ahead

What if you keep moving l. This also doesnt work because [1..5]is also a valid segment.  So we are not sure whether to move l or r. 

We are in dillemma. I know one thing for sure, as of now I cannot figure out where to move l or r if Im looking for a sum equivalent to the goal because, of the equal to sign,

And why is the problem coming up? because we have zeroes. On removing zeroes sum is not getting affected. That is where the problem is coming up

   l
[1 0 0 1 1 0] and goal = 2
         r
cnt = 2

   l
[1 0 0 1 1 0] and goal = 2
           r 
cnt = 2


SO we need to find a better solution. I know that I cannot solve this problem to find out the exact sum equivalent to the goal.
But can I do this. Lets try to solve a different problem and see If I can figure out a sliding window solution to it.

Can I figure out the -- no of subarrays where sum <= goal

I know that the problem is asking you to find equal to goal, but Ill try to solve it for lesser than equal to goal

l
[1 0 0 1 1 0] and goal = 2
r
sum = 1 <= goal  cnt = 1 


l
[1 0 0 1 1 0] and goal = 2
   r
sum = 1 and it is lesser than equal to goal cnt += (r - l + 1)
cnt = 1 + 2

l
[1 0 0 1 1 0] and goal = 2
     r
sum = 1 and it is lesser than equal to goal cnt += (r - l + 1)
cnt = 1 + 2 + 3

l
[1 0 0 1 1 0] and goal = 2
       r
sum = 2 and it is lesser than equal to goal cnt += (r - l + 1)
cnt = 1 + 2 + 3 + 4 

l
[1 0 0 1 1 0] and goal = 2
         r
sum = 3 which is greater than goal. SO definitely I cannot move r because the sum will then further increase. Ill need to trim down the sum, so for that Ill shrink from the front and remove the lth index element

   l
[1 0 0 1 1 0] and goal = 2
         r
sum = 2 which is lesser than equal to goal cnt += (r - l + 1)
cnt = 1 + 2 + 3 + 4 + 4

   l
[1 0 0 1 1 0] and goal = 2
           r
sum = 2 which is lesser than equal to goal cnt += (r - l + 1)
cnt = 1 + 2 + 3 + 4 + 4 + 5

cnt = 19 subarrays whose sum <= 2

Now I have an algorithm that gives me the no of subarrays whose sum <= goal. 
I need to find out the no of subarrays whose sum is equivalent to goal. Can I apply simple mathematics?
the ans for sum. == goal will be f(arr, goal) - f(arr, goal - 1)
f(arr, goal) - this gives how many are <= goal 
f(arr, goal - 1) - this gives how many are <= goal - 1

If I get both these values and subtract them, those many subarrays will have a sum equivalent to goal. Isnt it?

imaging the goal is given as 0, goal - 1 wil be -1 . There will be no subarrays with sum equivalent to -1.
hence we added that in the edge case



    int countSubarraysWithSumLesserThanEqualToGoal(vector<int> &arr, int goal){
        // edge case: the goal will always be >=0, but when you try to find for 2nd function call goal - 1 and if goal ==0, this makes goal < 0
        // and  since arr contains only 0s & 1s, we wont find any subarray 
        if(goal < 0) return 0;

        // keep on expanding until sum <= goal
        // the moment sum > goal -- start trimming
        int n = arr.size();
        int sum = 0;
        int cnt = 0;
        int l = 0, r = 0;
        while(r < n){
            sum += arr[r];
            while(sum > goal){
                sum -= arr[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }

        return cnt;

    }

    int numSubarraysWithSum(vector<int>& arr, int goal) {
        int n = arr.size();
        // this gives me no of subarrays with sum equivalent to goal
        return countSubarraysWithSumLesserThanEqualToGoal(arr, goal) - countSubarraysWithSumLesserThanEqualToGoal(arr, goal - 1);
    }

    TC: O(2 * 2n)
        outer whilse loop runs for n. Inner loop runs overall n steps throughout the entire journey, not at an individual occurence. 
        Hence n + n = 2*N 
        Can I say the TC of this function is O(2 * N) at the worse possible scenario. This is the worst possible test case. 
        It is not going to happen every now & then.

        and Im calling this function f 2 times, so the tc willl be O(2 * 2N)


    SC: O(1)
        -- I have optimised my sc. Yes, I have compromised a bit on the time, but it will be for extreme bad test cases, not for everything.



can we optimise 2 * n to n Is it possible to get rid of the inner while loop?
No, here we cannot apply that optimisation that we did in max Consecutive ones 3. Over here we have to count the no of subarrays, in case of count 
probably this optimisatoin will not work 

ex: [1 0 1 0 1], goal = 1
Count no of subarrays with sum <= goal 

If you apply the optimisation and calculate this count -- you will get Wrong ans. In case of count we probably need to traverse till end for l.
Thereby moving just 1 step doesnt work because then you will miss out on subarrays 