You are standing at 0th index. You have to figure out if you can reach the last index 

arr[] = [2, 3, 1, 0, 4]
ans: true  

arr[] = [3, 2, 1, 0, 4]
ans: false

Intuition -- 
we will think in the reverse direction. My target is to reach n-1 th index 
I''ll start from i = n-2 th index and I''ll check if I can reach my target. 
If I can -- then my revised target would be i 
In this way we will keep on revising our target 

So instead of figuring out whether we can reach the target from 0th index -- we'll check if we can reach it from n-2 th index 
If we are able to reach from n-2 th index, then my goal should be to figure out whether we can reach n-2 th pos or not.
If we are able to reach n-2 th position, then anyway we would be able to reach our target n-1 since we already checked for that condition 

At the end just check if your target == 0 because this would be only possible if you can reach the original target of n-1 th index from this position.

int target = n-1;
for(int i = n - 2; i >= 0; i--){
    if(i + arr[i] >= target){
        // revised target would be i
        target = i;
    }
}

return target == 0;

// THis is a classic approach of approaching the problem from the reverse direction

TC: O(n)    -- one simple for loop iteration 
SC: O(1) -- not using any extra space just 1 variable which is practically constant 





-- Another way of looking at this problem could be 

If we approach it from the front direction

Let me define a variable maxReach which keeps track of my max reach. If at any point max_reach crosses n-1 ie max_reach >= n-1 --> we will return true 
since we ensured that we are able to reach our destination 

I''ll start iterating from 1st index : If i + nums[i] > max_reach: max_reach = i + nums[i]
I''ll update my max_reach -- and if max_reach >= n-1: return true 
Also if i crosses max_reach any point: return false 
    because max_reach is the farthest point we can go. It is not possible to move beyond this point. Hence if(i > max_reach) i.e i has crossed max_reach -- we simply return false 
    i should always be <= max_reach
    The max that you were able to reach was max_reach. As a person you cannot arrive at this point(i) -- hence we return false 

1 edge case to handle here is if n == 1:
    you wont go inside for loop and will directly return false: hence we need to handle this condition separately 


** NOTE: Pls tell this edge cases in interviews: ** 

The catch over here is 0s. If you''re able to cross 0s, you will always be able to reach the end.
And if there are no zeroes -- then you will always be able to reach target.



bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;     // need this condition here -- since we're directly returning false in case we dont land inside for loop
        int maxReach = nums[0];         
        for(int i = 1;i < n; i++){  
            if(i > maxReach) return false;  
            if(i + nums[i] > maxReach){
                maxReach = i + nums[i];
            }
            if(maxReach >= n-1) return true;
        }
        return false;
    }

TC: O(n)    -- one simple for loop iteration 
SC: O(1) -- not using any extra space just 1 variable which is practically constant 


// Better code 
bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // removed the extra if condition
        int maxReach = nums[0];         

        for(int i = 1;i < n; i++){  
            if(i > maxReach) return false;  
            if(i + nums[i] > maxReach){
                maxReach = i + nums[i];
            }
            if(maxReach >= n-1) return true;    // adding this to optimise: if we're able to reach in the middle -- return true. no need to travel till the end 
        }
        
        // if you are coming out of for loop: this means if(i > maxReach) condition never executed & hence return true
        return true;
    }


Solution 1 of approaching from the reverse direction is more intuitive here. Keep this approach in mind -- very useful in such situations