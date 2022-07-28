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