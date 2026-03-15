1547. Minimum Cost to Cut a Stick

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
Return the minimum total cost of the cuts.

Constraints:

2 <= n <= 10^6
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.






We have a lot of options to start with  

[1, 3, 4, 5]        n = 7
Assume if I cut at 4, sticks will break into (0-4) and (4-7) and I will be left with [1,3] and [5] cuts which basically belong to left and right portion of my partition 
That is why we need the input[] to be sorted 
[1,3] cuts belong to (0-4) stick and [5] cuts belong to (4-7)
                                   i     k   j     
If I make a subtle change in cuts [1, 3, 5, 4]
cut at 5 (0-5) and (5-7)
[1,3] cuts belong to (0-5) but [4] cut does not belongs to (5-7)


cuts = [1, 3, 4, 5] 
Now we know why we need to sort the cuts[] array. So that after making ith cut, all the cut positions on the left side of ith cut belong to (0-i) stick and all the cut positions on the right side of ith cut belong to (i-n) stick

i          j 
[1, 3, 4, 5]. N = 7 lo = 0, hi = 7

k = i to k = j
If I cut at arr[k] position, then I will be left with (lo to arr[k]) and (arr[k] to hi) sticks and (i to k-1) and (k+1 to j) cuts will be remaining

lo and hi denotes the end points of the range
i,j denotes the endpoints of the cuts[]
if cuts[] is empty , cost is 0 -- base case i.e if i > j return 0

    ---------- only this are valid cuts 
[0, 1, 3, 4, 5, 7]
    i     k  j
I have just inserted 0 and length of the stick i.e n on the left and right side.

Imagine I am making a cut at 4, cost is length of that stick in which 4 is present 
cost = cuts[j+1] - cuts[i-1] = 7 - 0 = 7 (this is the length of the stick)

Now I need to solve for [1,3] and [5] cuts. Imagine 4 was at kth index. I have to solve i to k-1 and k+1 to j 
because I did a partition on k, so I need to solve for i to k-1 and k+1 to j 
and since the array is sorted, the subproblems are independent. I can solve them independently and compute my ans for the current cut  

0   1  2  3  4  5
[0, 1, 3, 4, 5, 7]
    i        j
    k. k. k. k 
I will start with f(1,4)

I can pick any one from 1 to 4 as the first cut
base case: In partition DP if i crosses j i.e i > j return 0 
f(i,j){
    if(i > j) return 0;
    int minCost = INT_MAX;
    for(int k = i; k <= j; k++){        // I can pick any cut from i to j
        int cost = cuts[j+1] - cuts[i-1] + f(i,k-1) + f(k+1,j);
        // costing I will incur is cost[j+1] - cost[i-1] == we intentionallly added 0 and n to the ends of the array. This will help us to calculate the cost 
        minCost = min(minCost,cost);
    }
    return minCost;
}

 
How to know if this problem uses concept of partition Dp
When we sort the cuts position and cut at any position, it results in 2 sticks of length 0 to arr[k] and arr[k] to n
i and j denotes the endpoints of the cuts[] array. choosing kth cut will result in (i to k-1) cuts and (k+1 to j) cuts which will belong to (0-arr[k]) and (arr[k]-n) sticks respectively.


NOTE: In order to make 2 subproblems independent we have to sort the arr. The resulting subproblems must be independent of each other.  


class Solution {
public:
    vector<int> cuts;
    int t[103][103];
    int solve(int i, int j){
        if(i > j) return 0; // base case
        // added memoisation
        if(t[i][j] != -1) return t[i][j];

        int minCost = INT_MAX;
        for(int k = i; k<=j; k++){ // cutting at arr[k]
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1) + solve(k+1, j);
            minCost = min(minCost, cost);
        }
        return t[i][j] = minCost;
    }

    int minCost(int n, vector<int>& arr) {
        arr.push_back(n);
        arr.insert(arr.begin(),0);      // inserted 0 and n at the ends of the stick
      
        sort(arr.begin(), arr.end());       // sorting the arr[] is important 
        
        memset(t, -1, sizeof(t));
        cuts = arr;                       // created a global ref so that we don need to pass cuts[] in the function calls
        return solve(1, cuts.size()-2);     // NOTE: we pass 1st and second last index as boundary. The endpoints are intentionally added that will help us to determine the cost of the kth cut 
    }
};

// NOTE: Instead of adding 0 and N initially I took 2 more variables lo and hi to track the endpoints of the stick to determine the length of the stick. 
// But this led to 4 changing parameters in the function call. Instead this is a good hack and this works because the position at which you are making the cut will form the endpoint of the stick in the subproblem 

// TC: O(len^3) - O(len^2) for memoisation + O(len) for the loop where len is the length of the cuts[]
// SC: O(len^2) for the memoisation table