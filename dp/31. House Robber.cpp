// HOUSE ROBBER 1
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

// we have to return the max amount of money that can be stolen -- maximise/minimise final value --> dp

solve(i){
    // base case: if i>= house.size() return 0              no house available -- return 0
    // skip ith house
    solve(i+1)
    
    // rob ith house
    house[i] + solve(i+2)

}

// TC: Optimsed using dp array for memoisation purposes O(N)
// SC: O(N) for dp[]

Follow UPs
Maximum Product Subarray        -- DONE
Medium
House Robber II                 -- DONE
Medium
Paint House
Medium      -- LC Premium
Paint Fence
Medium      -- LC Premium
House Robber III                -- DONE
Medium
Non-negative Integers without Consecutive Ones
Hard
Coin Path
Hard        -- LC Premium
Delete and Earn                 -- DONE
Medium
Solving Questions With Brainpower
Medium
Count Number of Ways to Place Houses
Medium
House Robber IV                 -- DONE
Medium
Mice and Cheese
Medium
Largest Element in an Array after Merge Operations
Medium





// PROBLEM 2 --  HOUSE ROBBER 2:
// same problem we've to determine the max amount of money that can be stolen, the only change is houses are arrange in a circular fashion
// so houses 1 and n are adjacent to each other.
// you cannot stole both 1 and n together. so 
// either you stole from house 1 to n-1 or you stole from house 2 to n. 
// Return the max of both cases
// ans = max(solve(house[1..n-1]), solve(houses[2...n]))

int n = houses.size();
vector<int> h1(houses.begin(), houses.begin()+(n-1));
vector<int> h2(houses.begin()+1, houses.end());

// TC: O(N) using memoisation
// SC: O(N) for dp[]


// Follow UPs
Paint House
Non-negative Integers without Consecutive Ones
HARD
Paint Fence 
MEDIUM  -- LC Premium
Paint House
MEDIUM  -- LC Premium
Coin Path 
Hard    -- LC Premium




// PROBLEM 3 --  HOUSE ROBBER 3:
// Houses are arranged in the form of a binary tree. You cannot rob 2 direclty linked houses
solve(root){
    // base condition: empty tree, no house to rob -> return 0
    if(root == NULL) return 0;

    // if you skip root
    int op1 = solve(root->left) + solve(root->right)

    int op2 = 0;
    // if you rob root
    if(root->left)                  // call only if root->left exists
    op2 += solve(root->left->left) + solve(root->left->right)
    if(root->right)                 // call only if root->right exists
    op2 += solve(root->right->left) + solve(root->right->right)

    // ans for this root will be max of both options
    return max(op1, op2);
}
// Memoise the ans for each root, to avoid same computations again
// TC: O(N)
// SC:O(N)  where N is the size of the tree ( N nodes)




HOUSE ROBBER 4
// Logic defined inside this solve block
solve(){
    // Robber will not steal from adjacent houses. He'll steal atleast k houses 
    // and Robber's capability is defined as max amount of money he steal from one house of all the houses he robbed.
    // We have to return the minimum capability of the robber of all the possible ways to steal at least k houses
    // minimise capability means we have to minimise the max value that he steals 

    Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 109
    1 <= k <= (nums.length + 1)/2

    Example 1:

    Input: nums = [2,3,5,9], k = 2
    Output: 5
    Explanation: 
    There are three ways to rob at least 2 houses:
    - Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
    - Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
    - Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
    Therefore, we return min(5, 9, 9) = 5.
    Example 2:

    Input: nums = [2,7,9,3,1], k = 2
    Output: 2
    Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.


    Initial Intution -- wrong
    // I'm at the ith house, and we need to rob atleast k houses(mandatory)
    solve(i,k,cap,res){
        if(k==0){
            res = min(res, cap);
            return;
        }
        // skip ith house
        solve(i+1, k, cap, res)
        // rob ith house
        solve(i+1, k-1,max(cap,houses[i]),res)
    }



    // Hint here is if I keep X as my capability and I'm able to choose K non contiguous elements then for any capability greater than X also I'll be able to choose X elements
    // Minimise the maximum value as much as we can --> try Binary Search (2nd pattern)

    lo = *min_element(all(arr)), hi = *max_element(all(arr));

    capability will always lie in range from [lo,hi]
    apply binary search:
    if you are able to find K non contigous houses with m as the capability, then m could be your ans. Update the hi = m - 1 to find potential lower capability
    if you are not able to find K non contigous house for m capability, then you wont be able to find for value < m. SO update lo = m + 1

    ifPossible(vector<int>& input, int k, int cap){
        int cnt = 0;
        // we have to find the count of values in input which are less than cap. return true if cnt >= k    --> this means we were able to find k non contigous houses
        for(int i=0;i < input.size(); i++){
            if(input[i] <= cap){
                cnt++;
                i++;            // I cannot use the next element, hence skip this
            }
        }
        return cnt >= k;
    }

}
    
Follow up:
    Container with Most Water
        solve(){
            Here essentially we have to find 2 pillar (i,j) that can contain the maximum amount of water

            Initial thought was we can fix my left pillar at i and run my right from j = i+1 to n.
            min(nums[i], nums[j]) will be my bottleneck for the choosen pair(i,j). Calculate the ans for current pair which will be min(nums[i], nums[j]) * (j - i) and update ans accordingly.
            This is O(n^2) solution.

            The two-pointer approach is the key to solving the "Container With Most Water" problem in O(N) time.
            
            Intuition
            Take 2 pointers i  = 0 and j = n-1
            min(nums[i], nums[j]) is the bottleneck value and in order to maximise the area I would want to increase my height i.e min(nums[i], nums[j]) and width (j - i)
            ans for current window = min(nums[i],  nums[j]) * (j - i);
            if nums[i] < nums[j]: increment i
            else decrement j
            By doing this, we are ensuring we are trying to maximise my bottleneck value
        }
        

    Trapping Rain Water
    Hard
        solve(){
            // we'll have to find the amount of water that each index can trap
            
            // NO we dont have to find ngr[i] and ngl[i], Instead I need the largest value on rhs and lhs of i
            int left[n], right[n];
            // left[i] = max(height[0]..height[i])
            left[0]=height[0];
            for(int i=1;i<n;i++){
                left[i] = max(left[i-1], height[i]);
            }

            right[n-1] = height[n-1];
            for(int i=n-2;i>=0;i--){
                right[i] = max(right[i+1], height[i]);
            }
            int ans=0;
            for(int i=1;i<n-1;i++){
                int val = min(left[i],right[i]) - height[i];
                if(val > 0) ans+=val;
            }

            return ans;
            
            // for this find the next greater value(striclty greater) on the right and on left
            // min(ngr[i], ngl[i]) - arr[i] --> this is the amt of water trapped at each index 
            // take sum of this for all i from 0 to n

            // to find ngr[i] and ngl[i], use stack 
            stack<int> s;           // will store indexes
            vector<int> ngl(n), ngr(n);
            ngl[0] = -1;        // there is no greater element on left of 0th index
            s.push(0);
            for(int i=1;i < n;i++){
                // keep on popping until you find a value on stack top > a[i]
                while(!s.empty() and a[s.top()] <= a[i]) {
                    s.pop();
                }
                if(s.empty()){
                    ngl[i] = -1;        // no greater element exists on lhs of i
                }
                else{
                    ngl[i] = s.top();   // this is the index of the next greater element of i on its left   
                }

                s.push(i);
            }


            // similarly fill ngr[i]

        }

    Trapping Rain Water 2
    Hard

    Pour Water 
    Medium LC Premium


    Maximum Tastiness of Candy Basket 




// MAXIMUM PRODUCT SUBARRAY
array contains +ve, -ve and 0s. Find the subarray with largest product and return the product 

Intution:
At ith index, I can either fresh start 
or I can extend previous subarray

ans = nums[0];
max = nums[0]
min = nums[0]

newmax = max(arr[i], arr[i]*max, arr[i]*min);
newmin = min(arr[i], arr[i]*max, arr[i]*min);

No need to break at 0s, since we are already considering a fresh start from ith index.  

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // NOTE: test cases are designed in a way that we need to pick atleast one element. We cannot choose empty subarray
        int ans = nums[0];
        int maxp = nums[0];
        int minp = nums[0];
        for(int i=1; i < n; i++){
            int newmax = max({nums[i], nums[i] * maxp, nums[i] * minp});
            int newmin = min({nums[i], nums[i] * maxp, nums[i] * minp});
            ans = max({ans, newmax, newmin});
            maxp = newmax;
            minp = newmin;
        }

        return ans;
    }
};
// TC: O(n)
// SC: O(1)


Follow UPs
Maximum Subarray
Medium
Product of Array Except Self        -- DONE
Medium
Maximum Product of Three Numbers
Easy
Subarray Product Less Than K
Medium



// Product of Array Except Self

// solution1: very first thought that came to my mind is compute left[i] and right[i]
// where left[i] stores the product of array nums[0..i-1] and right[i] stores the product of array nums[i+1..n-1]

// solution: using the same logic as sol1, we'll only use a res[] which willl ultimately hold the final res.
// For traverse left to right and store left product at each index 
// i.e res[i] = stores product of nums[0..i-1]
// Then traverse in the reverse direction and update the res[i] to also store the product of right side.
// Instead of using left[] and right[], I computed the answers in my result array itself

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = 1;     // res[i] stores product of nums[0..i-1]
        // res[0] = 1 since there is nothing towards the left of 0
        int left = nums[0];
        // traverse left to right
        for(int i=1;i<nums.size();i++){
            res[i] = left;
            left = left * nums[i];
        }

        int right = nums[n-1];
        // traverse from right to left;
        for(int i=n-2;i>=0;i--){        // res[i] already stores the product of prefix [0..i-1]
            res[i] = res[i] * right;
            right = right * nums[i];
        }

        // In the res[] itself we first computed the left product and then the right product using 2 for loop iterations
        // Using no extra space other than the res[] itself
        return res;
    }
};

// TC: O(N)
// SC: O(N) for res[]



// SLIDING WINDOW MAXIMUM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        
        vector<int> res;

        deque<int> dq;

        for(int i=0;i<n;i++){
            // pop until the q.front() <= i-k. -- out of bound for curr window. Reason we need <= here is all positions which are less than equal to i-k are out of bound from my current index
            while(!dq.empty() and dq.front() <= i-k) 
                dq.pop_front();
            
            // pop until the curr element is >= element at dq.back position (reason I'm using >= here is I want to have the latest position in my dq for a value that has multiple occcurences. All the equal value positions will be removed and we'll just capture the latest position)
            while(!dq.empty() and nums[dq.back()] <= nums[i]) 
                dq.pop_back();

            dq.push_back(i);

            if(i >= k-1) res.push_back(nums[dq.front()]);
        }

        return res;


    }
};

// Time Complexity:
// O(n)

// Each element is pushed and popped from the deque at most once.
// All operations inside the loop (push, pop) are amortized O(1).
// So, the total time is O(n).

// Space Complexity:
// O(k)

// The deque stores at most k indices at any time (the current window).
// The result array uses O(n) space, but the extra space for the algorithm is O(k).

Follow UPs
Minimum Window Substring        -- DONE
Hard
Min Stack
Medium
Longest Substring with At Most Two Distinct Characters
Medium
Paint House II
Hard
Jump Game VI
Medium
Maximum Number of Robots Within Budget
Hard
Maximum Tastiness of Candy Basket
Medium
Maximal Score After Applying K Operations
Medium


// MIN WINDOW SUBSTRING
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string ""

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105

string solve(string s, string t){
    // create 2 maps mp1(for s) and mp2(for t)
    int i = 0, j=0, n = s.length();
    while(j < n){
        mp1[s[j]]++;

        if(isSubset(mp1,mp2)){      // isSubset() is an O(n) operation -- this can be optimised
            // keep on popping from the front until ith char freq > its desired frequence
            while(i<=j and mp1[s[i]] > mp2[s[i]]){
                mp1[s[i]]--;
                i++;
            }
            // first shrink the string and then compute ans. This [i..j] could be my potential ans
            ans = min(ans, j-i+1);

        }
        j++;
    }
}
// TC: O(N^2) because of isSubset() function
// SC: O(N)

// optimising solution to avoid using isSubset(mp1,mp2) function. Essentially this function checks if mp2 is a subset of mp1, but performing this each time is an expensive operation
// required stores the count of desired char which we can get from mp2 as required = mp2.size()
// Now while expanding my window, moment mp1[s[j]] == mp2[s[j]], I'll do formed++.
// the moment formed == required, we have got one possible ans
// using this 2 variables formed and requried, we optimised the tc to O(N) 
string solve(string s1, string s2){
    map<int,int> mp1,mp2;
    for(auto ch: t) mp2[ch]++;

    while(j < n){
        mp2[s[j]]++;
        
        if(mp2[s[j]] == mp1[s[j]]) formed++;
        
        while(i<=j and formed==required){
            if(j-i+1 < length){
                length = j-i+1; start = i; end = j;
            }
            mp2[s[i]]--;
            if(mp2[s[i]] < mp1[s[i]]) formed--;
            i++;
        }

        j++;
    }

    return s.substr(start, end-start+1);
}

// TC: O(N)
// SC:O(N)



209. Minimum Size Subarray Sum

return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j= 0, curr_sum = 0,min_len = INT_MAX, n = nums.size();
        while(j < n){
            curr_sum += nums[j];
            while(i <= j and curr_sum >= target){
                min_len = min(min_len, j - i + 1);
                curr_sum -= nums[i];
                i++;
            }
            j++;
        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};



718. Maximum Length of Repeated Subarray
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100

class Solution {
public:

    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
    
    // Very Brute force solution. Definitely TC is greater than O(N^2) since you are serialising each vector 

    //     map<vector<int>, int> mp; // array -> freq

    //     for(int i=0;i<n;i++){
    //         vector<int> sub;
    //         for(int j=i;j<n;j++){
    //             sub.push_back(nums1[j]);
    //             mp[sub]++;
    //         }
    //     }

    //     int ans = 0;

    //     for(int i=0;i<m;i++){
    //         vector<int> sub;
    //         for(int j=i;j<m;j++){
    //             sub.push_back(nums2[j]);
    //             if(mp.count(sub)){
    //                 ans = max(ans, (int)sub.size());
    //             }
    //         }
    //     }

    //     return ans;



    // Better solution: USING LCS 
    // WHY LCS: Whenever you are given 2 string or arrays and you are asked to find the longest common subsequence or subarray, LCS is the way to go
    // Recurrence:
    vector<vector<int>> dp(n+1, vector<int>(m+1));  

    for(int i=0;i <= n;i++){
        
        for(int j=0;j <= m;j++){
        
            if(i==0 or j==0) dp[i][j] = 0;
        
            if(s[i-1] == t[i-1]){
        
                dp[i][j] = 1 + dp[i-1][j-1];
        
            }
            else{
        
                dp[i][j] = 0;       // since we dealing with subarrays here
        
            }

            ans = max(ans, dp[i][j]);
    
        }
    
    }

    return ans;

    }
};
TC: O(n*m)  
SC: O(n*m)


Follow Ups
Find the Maximum Length of a Good Subsequence I
MEDIUM
Find the Maximum Length of a Good Subsequence II
HARD

