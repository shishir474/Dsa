Shortest Job First (SJF)

Our task is to compute the average waiting time for all the processes following the Shortest Job First (SJF) algorithm.

We are given the processing time of n processes. 

bt = [4, 3, 7, 1, 2]

since we need to follow shortest job first, we will sort the array in ascending order.
The process with the least execution time, will be processed first.
bt = [1, 2, 3, 4, 7]

we need to return the nearest smallest integer 

int findWaitingTime(int bt[], int n) 
{ 
    sort(bt, bt + n);
    int preSum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        ans += preSum;
        preSum += bt[i];
    }
    return ans/n;
}

TC: O(nlogn) + O(n)
SC: O(1)