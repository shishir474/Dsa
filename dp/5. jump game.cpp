JUMP GAME

Determine if you can reach end of array
You are given an integer array nums. You are initially positioned at the array s first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
// DP Solution: 
class Solution {
public:
    int t[10002];
    bool solve(vector<int> &nums, int i){
        if(i >= nums.size()-1) return true;
        if(t[i] != -1) return t[i];
        for(int k=1;k<=nums[i];k++){
            if(solve(nums, i+k)) return t[i] = true;
        }
        return t[i] = false;
    }

    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums, 0);
    }
    // TC: O(n^2), SC: O(n)
    // For each index, the function may try up to nums[i] jumps, which in the worst case can be upto n, for each of the n indices.
    // Memoization avoids recomputation, but in the worst case, every state can try all possible jumps.

};


// Solution using Greedy Approach
class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int goalPost = n-1;         // initially my goalPost/target is n-1
        for(int i=n-2;i>=0;i--){    // I'll check if I can reach the goalPost from ith index, if I can then I'll update the goalPost to i, else I'll breakout of the loop and since goalPost isn't equal to 0, I'll return false
            if(i + nums[i] >= goalPost){
                goalPost = i;
            }
        }
        return goalPost == 0;
    }
};


   G  G  G  G  G
// 2, 3, 1, 1, 4
               
               G
// 3, 2, 1, 0, 4

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105


  bool canJump(vector<int>& a) {
        if(a.size()==1) return true; // corner case 1
        if(a[0]==0) return false;  // corner case 2
        
        int jumps=1;
        int mr=a[0];
        int steps=a[0];
        int n=a.size();
        for(int i=1;i<n;i++){
            if(i==n-1) return true;
            mr=max(mr,i+a[i]);
            steps--;
            if(steps==0){
                jumps++;
                if(i>=mr) return false;
                steps=mr-i;
            }
        }
        
        return true;
    }




JUMP GAME 2 -> To find min no. of jumps