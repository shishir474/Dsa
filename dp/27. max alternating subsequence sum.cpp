1911. Maximum Alternating Subsequence Sum

The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.

For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

 

Example 1:

Input: nums = [4,2,5,3]
Output: 7
Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
Example 2:

Input: nums = [5,6,7,8]
Output: 8
Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.
Example 3:

Input: nums = [6,2,1,2,4,5]
Output: 10
Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105


// Logic: 
In all subsequence based problems, we have an option to either pick or drop ith element. 
Subsequence is essentially a non contiguous array. and while forming it you have to decide whether you want to pick ith element or not.

pick - non pick concept --> is used in subsequence based problems

// Now the twist here is , if you dont pick ith element, you simply move to i+1.
But if you pick ith element, then depending on whether it''s an even/odd indexexed element in your subsequence, you need add/subtract it.
for keeping track whether it is an even/odd indexed element -- we can use a flag f. if f==0 then the element is at even indexed position in my subsequence else it is at the odd indexed position in my subsequence.
solve(i,f){
    // base case: i >= arr.size()   return 0;

    // don't pick ith element
    int opt1 = solve(i+1, f);

    int opt2 = 0;
    //pick ith element 
    if(f == 0){ // element's gonna be placed at even index in subs, hence add it & now next element will be placed at odd index position
        opt2 = arr[i] + solve(i+1,f^1);
    }else{
        opt2 = -arr[i] + solve(i+1,f^1);
    }

    return max(opt1, opt2);
}

// TC: O(n)
// SC: O(2*n) for dp[][] which is essentially O(n)



class Solution {
public:
     long long t[100002][2];
    
     long long solve(vector<int>& a, int i, int f){
        if (i>=a.size()) return 0;
        
        if (t[i][f] != -1) return t[i][f];
        
        long long s1 =0;
        if (f==0){
            s1 = a[i] + solve(a,i+1,f^1);
        }else{
            s1 = -a[i] + solve(a,i+1,f^1);
        }
        
        long long s2 = solve(a,i+1,f);
        
        return t[i][f] = max(s1,s2);
    }
    long long maxAlternatingSum(vector<int>& a) {
        memset(t,-1,sizeof(t));
        return solve(a,0,0);
        
    }
};

// Now depending on if we are considering picking the current element & if it an even index eleement of our subsequence, we will add that element or if it's an odd index element, we will subtract that element
// If we are considering dropping the current element, just move on to the next one 
// In order to find out the if the current element is an even or odd index element, we will use a flag. flag 0 means it's an even index element and 1 means odd index element in our subsequence

// Recurrence relation
// solve(i,f)
// flag 0 means it's an even index element of our subsequence 
// flag 1 means it's an odd index element of our subsequence
// If I pick current index, now depending on f(flag) value if it is 0, then we will add a[i], if it is 1 we will subtract a[i]
//     if(f==0) 
//         a[i] + solve(i+1, f^1)
//     else 
//         -a[i] + solve(i+1, f^1)

// If I ignore current index - just call i+1 with the same flag value because we haven't considered the current flag
    // solve(i+1,f)
