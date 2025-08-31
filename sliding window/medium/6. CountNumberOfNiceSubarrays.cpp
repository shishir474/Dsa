you have to count the no of subarrays that contains exactly k odd elements 

arr= [1 1 2 1 1 ], k = 3 

[0..3], [1..4] -- contains 3 odd elements


Brute force:
Check all the subarrays and count those that contains exaclty k odd elements -- 
TC: O(n^2)
SC: O(1)


-------------------------------------------------------
There is a prerequisite to this problem. Please go and solve Binary Subarrays With Sum 
In that particular problem statement we were given an arr (it was a binary array). You have to -- count the no of subarrays with sum equivalent to the goal.

Ill try to convert this particular problem into that problem. Lets understand how? 

What if I say Hey listen -- I;ll consider all the odd numbers as 1 and all the even numbers as 0. If I consider this can I say my arr will look something like

If its an odd no, Ill write it as 1 else Ill write it as 0

original arr =    [1 1 2 1 1]. k = 3
transformed arr = [1 1 0 1 1]

Cna I say Im counting the no of subarrays where the sum is equivalent to k. Can I say this? Isn''t it.
because if I pickup [0..4] subarray I know 0, 1, and 3rd index elements are odd and the sum will be 3 which is equivalent to k.

So this problem is nothing but similar to the previous problem.

The problme setter has just twisted some words here & there. Its very important that you identify such problems.



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
            sum += (arr[r] % 2);
            while(sum > goal){
                sum -= (arr[l] % 2);
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