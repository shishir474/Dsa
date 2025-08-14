// 2602. Given an array you have to make all array elements equal to queries[i]

// Operation allowed : you can either increase an element by 1 or decrease an element by 1 in one operation

// all the values that are less than queries[i] will be increased to queries[i]
// all the values that are greater than queries[i] will be decreased to queries[i]

input = [3,6,1,8] 
queries[5]

you have to make all elements equal to 5
2 + 1 + 4 + 3 = 10

sort the array
For finding the elements < x ==> you can use lower_bound
For finding the elements > x ==> you can use upper_bound
calculate the prefix sum 

[1, 3, 6, 8] 
# of elements < 5 (basically find lower bound of 5) = 2
(5 * 2) - (1 + 3) = 6

# of elements > 5 (basically find upper bound of 5) = 2
(5 * 2) - (6 + 8) = 4

Total operations required 10 


Constraints:

n == nums.length
m == queries.length
1 <= n, m <= 105
1 <= nums[i], queries[i] <= 109


class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> res;
        
        int n = nums.size();
        
        sort(nums.begin(),  nums.end());

        // constructing prefix[]
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i=1;i<prefix.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(auto val: queries){
            // convert all values of nums to val
            // find the. # of elements < val and > val --> all these needs to be transformed
            // This can be easily done using lower and upper bounds --> but for this array needs to be sorted. hence sort the array 

            // get all the elemnts < val --> all those needs to be incremented 
            // find lower_bound(val) - 1
            // idx here will be equal to #of elements < val
            long long idx = lower_bound(nums.begin(), nums.end(), val) - nums.begin();
            // sum of elements < x -- this could be found using prefix_sum
            long long prefix_sum = (idx != 0) ? prefix[idx - 1] : 0;
            long long num_elements_less_than_val = idx;
            long long target_sum = num_elements_less_than_val * val;
            long long add_operations = target_sum - prefix_sum;

            // get all the elements > val --> all those needs to be decremented 
            long long idx2 = upper_bound(nums.begin(), nums.end(), val) - nums.begin();
            long long suffix_sum = prefix[n-1] - ((idx2 > 0) ? prefix[idx2 - 1] : 0);
            long long num_elements_greater_than_val = n - idx2;
            long long target_sum2 = num_elements_greater_than_val * val;
            long long sub_operations = suffix_sum - target_sum2;

            long long ans = add_operations + sub_operations;

            res.push_back(ans);
        }

        return res;
    }
};

Follow Ups
Minimum Moves to Equal Array Elements           -- DONE
Medium                                          
Minimum Moves to Equal Array Elements II        -- DONE
Medium                                          
Minimum Cost to Make Array Equal
Hard
Sum of Distances
Medium





453. Minimum Moves to Equal Array Elements
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

Example 1:

Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
Example 2:

Input: nums = [1,1,1]
Output: 0
 
Constraints:

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109
The answer is guaranteed to fit in a 32-bit integer.


// Intuition:

problem statement is a bit misleading. In one operation, you''ll increment n-1 values or I can say all the values of the array except the current one 
Let's get one thing out of the way first - let's just bloody sort the damn array before worrying about anything else

Now, the idea is to reach a state where all elements are equal - simple, fair enough.

In the process, the element which will change the most is the first element - the leftmost one - while, conversely, the element which will change the least is the last one, the rightmost one i.e. The sodding array is sorted, after all.

So for nothing but the heck of it, let's look at the whole thing from the perspective of the first element.

Let's imagine the first element setting an initial task for itself - I have to catch up with my neighbor (i.e. second) element. So what does it do - increments itself and all other elements, except the second one of course, by the exact difference between itself and the second element.

If the array was "1, 5, 6, 7" then the array change to "5 5 10 11".

Next, the first element expands it's horizons a bit and looks at the element just beyond the second one - the third element. It must catch up with the third element. So: every element, except the third element is upgraded by the difference between the first element and the third one. As a result, the array now is - "10 10 10 16".

Finally, only one element left that's towering above everyone else - the last element. In the final step, the array is modified to "16 16 16 16".



class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for(int i=1 ;i < n ;i++){
            ans += (nums[i] - nums[0]);
        }

        return ans;
    }
};

Follow Ups
    Maximum Running Time of N Computers
    Hard
    Pour Water Between Buckets to Make Water Levels Equal
    Medium
    Divide Players Into Teams of Equal Skill
    Medium
    Find Minimum Operations to Make All Elements Divisible by Three
    Easy




Minimum Moves to Equal Array Elements II
462. Minimum Moves to Equal Array Elements II

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
Output: 16
 

Constraints:

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109


// Similar to above problem, just that in the above problem the target was defined i.e queries[i] to which we needed to convert all the elemeents
// But in this problem the target is not defined, we need to find the optimal target that minimizes the moves

Why Median ?

Take an example, the input array after sorting is [1, 3, 5, 8, 10, 12]. Lets say we want to move all elments to x, so that we have minimum moves.

First, I think we all agree that x should be in the range 1 <= x <= 12. Simple math.

Second, it''s essential to observe that, when 1 <= x <= 12, |x-1| + |12-x| is a CONSTANT! So element 1 and element 12, these two guys don''t care where your x is, as long as x is in the range 1 <= x <= 12.
when 1 <= x <= 12, abs(x-1) + abs(12 - x) = 11  -- This value will remain constant

Then, let''s consider the subarray [3,5,8,10]. Basically we are repeating step 1 and step 2 again, x should be in 3 <= x <= 10, but exactly where, element 3 and element 10 don''t care about it, since |x-3| + |x-10| is a CONSTANT!
when 3 <= x <= 10, abs(x-3) + abs(10 - x) = 7  -- This value will remain constant

We repeat these steps, and find out that eventually, the x should be in the range 5 <= x <= 8. Technically speaking, x is not necessarily the median, any number between 5 and 8 works.
You can think the similar way if the number of elements is odd.


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // we'll always converge all the nos towards the median
        int n = nums.size();

        // always sort the array before calculating median
        sort(nums.begin(),  nums.end());
        
        //  in odd case, we'll have just one median -- all elements will converge to that
        // in even case,, we'll have 2 median, We can choose any number between median1 and median2. That'll work
        int median = nums[n/2];

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += abs(nums[i] - median);
        }

        return ans;
    }
};


Follow Ups
    Best Meeting Point
    Hard        LC Premium
    Minimum Operations to Make a Uni-Value Grid
    Medium
    Removing Minimum Number of Magic Beans
    Medium
    Minimum Operations to Make All Array Elements Equal
    Medium
    Minimum Cost to Make Array Equalindromic
    Medium
    Minimum Operations to Make Subarray Elements Equal
    Medium
    Minimum Operations to Make Elements Within K Subarrays Equal
    Hard