Maximum points you can obtain from the card 

You are allowed to choose k cards. Each time you can take once card from the beginning or from the end of the row.
Return the max points that you can earn.

cardPoints[] = {1,2,3,4,5,6,1}, k = 3
ans = 12 -- last 3 cards

The extreme naive sol. that I can think of is 
possible combinations:  -- these are the only ways in which the cards can be picked 

pick all the first 3 cards from the front 
{1,2,3}, {} = 6

or Pick 2 card from the front and 1 cards from the back 
{1,2}, {1} = 4

or Pick 1 card from the front and 2 cards from the back 
{1}, {6,1} = 8

or Pick 0 card from the front and all 3 cards from the back 
{}, {5,6,1} = 12

and out of all these configurations whichever gives you the maximum score, that will be your ans


Ill pick all the 4 elements from the front
       -------
arr = [6 2 3 4 7 2 1 7 1] k = 4
lsum = 15, rsum = 0, total = 15

Ill pick 3 elements from the front and 1 element from the right
       -----           -
arr = [6 2 3 4 7 2 1 7 1] k = 4
lsum = 11, rsum = 1, total = 12     (remove 4 from lsum & add 1 to rsum)

Ill pick 2 elements from the front and 2 element from the right
       ---           ---
arr = [6 2 3 4 7 2 1 7 1] k = 4
lsum = 8, rsum = 8, total = 16    (remove 3 from lsum & add 7 to rsum)

Ill pick 1 elements from the front and 3 element from the right
       -           -----
arr = [6 2 3 4 7 2 1 7 1] k = 4
lsum = 6, rsum = 9, total = 15     (remove 2 from lsum & add 1 to rsum)

Ill pick 0 elements from the front and 4 element from the right
                 -------
arr = [6 2 3 4 7 2 1 7 1] k = 4
lsum = 0, rsum = 11, total = 11     (remove 6 from lsum & add 2 to rsum)



int lsum = 0, rsum = 0;
for(int i = 0; i < k; i++) lsum += arr[i];

int max_sum = lsum;
for(int i = 1; i<=k ;i++){
    // remove i elements from lsum and i element from the rsum
    lsum -= arr[k - i];
    rsum += arr[n - i];
    max_sum = max(max_sum, lsum + rsum);
}

return max_sum ;

TC: O(k) + O(k) = O(2 * k)
SC: O(1)


NOTE: we dont need to store the prefix and suffix sum. 
Just maintaining 2 variables, lsum and rsum which represents the left sum and right sum works!

Exactly same logic as the below sol, but way better complexity. Also we are not using any kind of extra space here.


Other way in which this loop can be written is 

I know one thing for sure, that I have go from k-1 till 0th index 


int lsum = 0, rsum = 0;
for(int i = 0; i < k; i++) lsum += arr[i];

int max_sum = lsum;

int right_idx = n-1;
for(int i = k - 1; i>=0 ;i--){
    lsum -= arr[i];
    rsum += arr[right_idx];
    right_idx--;
    max_sum = max(max_sum, lsum + rsum);
}


THE trick here is -- if you can solve a problem only by using variables, pls use that -- dont fall into the trap of using a prefix sum 

-----------------------------------------------------------------------------------

int n = cardPoints.size();
vector<int> ps(n,0), ss(n,0);
ps[0] = cardPoints[0];
for(int i = 1; i< n; i++){
    ps[i] = ps[i-1] + cardPoints[i];
}
ss[n-1] = cardPoints[n-1];
for(int i = n-2; i>=0; i--){
    ss[i] = cardPoints[i] + ss[i+1];
}

// trying out all possible combinations
int ans = max(ps[k-1], ss[n - k]);
for(int i = k-2; i>=0; i--){
    ans = max(ans, ps[i] + ss[n - k + i + 1]);
}

return ans;

TC: O(n) + O(n) + O(n) = O(3 * n)
SC: O(n) + O(n) = O(2 * n)
