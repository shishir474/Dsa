Max consecutive ones 3

you will be given a binary array and you are allowed to flip at most k zeroes

You have to return the length of the max consecutive ones.


Strivers sol:
can we convert this problem to longest subarray with atmost K zeroes? yes, we can 

arr[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}

What will be the brute force? 
Generate all the subarrays and check for those which as atmost k zeroes 

int maxLen = 0;
for(int i = 0; i < n; i++){     // first loop runs for n 
    int zeroCnt = k;
    for(int j = i; j < n; j++){ // runs for somewhere around n -- not exactly n
        if(arr[j] == 0) zeroCnt--;
        if(zeroCnt < 0) break;
        maxLen = max(maxLen, j - i + 1);
    }
}

TC: O(n^2) -- somewhere around n^2
SC: O(1)

---------------------------------------------------------------

Better solution 

I need to optimise my brute force which was taking N^2. I have to optimise this somewhere around n.
The problem involves subarray. So whats the first algorithm that comes to your brain? 2 pointers & Sliding window 

l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
               r
You cannot consider this subarray because it crosses the threshold of k zeroes. From the naked eye [0,0] is the subarray that you would consider 
so move l I need to trim down from the front so that no of zeroes in the current window is always <= k

            l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
               r



l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
r

k =    2
1 - 1 + 1 = 1> maxLen = 1;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int l  = 0, r = 0;
        while(r < nums.size()){
            if(nums[r] == 0) k--;
            while(k < 0){
                if(nums[l] == 0) k++;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};

TC: O(2*n) -- 
What is driving the complexity? There is a while loop which is being driven r (right pointer) & it is going till the last so O(n) involved here 
Now inside the while loop there is another while loop. But the question is -- is the inner while loop always running till n? No its not
In total if you consider, then in the worst case the inner while loop will run till last and only once. SO O(n) overall, not during each iteratoin.

Hence the time complexity becomes 
O(n) + O(n) = O(2 * n)

SC: O(1) -- not using any extra space apart from 2 pointer variables which is going to take constant space 


--------------------------------------------------------------------------

most optimal Solution

               l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                              r 

ans = 6 

r = 0
while r < n:
    if arr[r] == 0:
        zero_cnt-=1
    if zero_cnt < 0:
        if arr[l] == 0:
            zero_cnt+=1
        l+=1
    if zero_cnt >= 0:
        ans = max(ans, r - l + 1)
    r+=1



here we will get rid of the inner while loop to reduce the complexity frmo O(2*N) to O(n)

This approach also uses sliding window, but we will be slightly smarter this time.

The time complexity is O(n) because we are not moving l to the extreme right unlike the above solution 

l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
r
l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
         r
len. =4 greater than maxLen, so update maxLen = 4, zeroes = 1 <= k, k = 2

l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
            r
len. =5 greater than maxLen, so update maxLen = 5, zeroes = 2 <= k, k = 2

l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
               r
zeroes = 3 which is not less than k , k = 2
So Ill have to trim down. In the betters solution we brought l to 4th index
here we just do l++
but before that if s[l] == 0, then zeroes-- 
Ill not update my ans until zeroes <= k 

   l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
               r
r-l+1 = 5, but zereos is not less than equal to K, so Ill not update my ans 
zeroes = 3 which is not less than k , k = 2

we knew that the max length was 5
Ill not allow the ans to be updated, till I get zeroes under 2 (basically <=2)

   l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                  r
zeroes are still 3, and the subarray l..r is of lenght 6, but Ill not be allowed to update maxLen because zeroes are still 3
So what Ill do is move l by 1 step, and since arr[l] == 1, zeroes still remains 3

      l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                  r
      l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                     r
subarray l..r is of lenght 6, but Ill not be allowed to update maxLen because zeroes are still 3

         l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                     r
         l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                        r
subarray l..r is of lenght 6, but Ill not be allowed to update maxLen because zeroes are still 3


            l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                        r
zeroes = 2, len of l..r is 5 which is same as maxLen -- so not updating maxLen


            l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                           r
len = 6 > maxLen and zeroes = 2 <= 2 
update maxLen = 6

            l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                              r
subarray len l..r = 7 Im not allowed to update since zeroes is 3 

               l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                              r
zereos = 2, len = 6, maxLen = 6 -- not updating maxLen 

               l
0  1. 2. 3. 4. 5. 6. 7. 8  9  10
1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
                                 r

Only difference between this and the previous sol was here when zeroes > k, we will just be moving l by one place.
In doing this, what we have succeded in doing this is 

int l =0, r = 0, maxLen = 0;
while(r < n){
    if(arr[r] == 0) zeroes++;
    if(zeroes > k){
        // just move l by 1 
        if(arr[l] == 0) zeroes--;
        l++;                            // doesnt matter if it got trimmed or not, Ill be moving the left 
    }
    if(zeroes <= k){
        maxLen = max(maxLen, r - l + 1);
    }
    r++;
}


TC: O(n) -- here we got rid of the inner while loop hence the tc reduces to O(n) 
This works bcoz, we are not allowing r to extend the size. r is moving, but Im not gonna allow it to extend the size. It still stays at the same size 
When I get a zero on left, then only Im allowed to extend if its greater than maxLen

SC: O(1)

l
1 1 1 1 0 0 0    k = 2
r

l
1 1 1 1 0 0 0    k = 1
        r
maxLen = 5 

l
1 1 1 1 0 0 0    k = 0
          r
maxLen = 6

l
1 1 1 1 0 0 0    k = -1
            r
You will need to trim the 4th index 0. But over here in this algo what we are doing is just move l since arr[l] != 0

  l
1 1 1 1 0 0 0    k = -1
            r
so keep the length l..r as 6 and move r -- r moves out. we stop
maxLen = 6


Whereas in the prev algo what we did was, we took l from 0th index to 4th index, till you got a zero 
and you reduced zeroes cnt to 2. You went till 4th index, but this doesnt helps because the size that you get is 2 which is definitely not greater than maxLen

So thats why the algo works