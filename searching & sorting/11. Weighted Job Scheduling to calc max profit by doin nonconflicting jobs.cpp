Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Example: 

Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250.  



struct Job{
    int start,finish,profit;
};

class Solution {
public:
    static bool compare(Job j1, Job j2){
        return j1.finish < j2.finish;
    }
    
    // this part can be optimised
    int latestNonConflictJob(Job arr[], int i){
        // doing ith job, so find lates non conflicting job wrt i
        for(int j=i-1;j>=0;j--){
            if(arr[j].finish <= arr[i].start) return j;        
        }
        return -1; 
    }

    int latestNonConflictJob(vector<Job>& arr, int i){
        // doing ith job, so find lates non conflicting job wrt i
        int ans=-1;
       int lo=0,hi=i-1;
       while(lo<=hi){
           int mid=lo+(hi-lo)/2;
           if(arr[mid].finish > arr[i].start) hi = mid-1;
           else{
               //arr[mid].finish <= arr[i].start
               ans = mid;
               lo = mid+1;
           }
       }

       return ans;
    }
    
    
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> arr;
        for(int i=0;i<startTime.size();i++){
            Job j; 
            j.start = startTime[i];
            j.finish = endTime[i];
            j.profit = profit[i];
            arr.push_back(j);
        }
        
        int n=arr.size();
        
        sort(arr.begin(), arr.end(), compare);
        
        int dp[n];
        dp[0] = arr[0].profit;
        
        for(int i=1;i<n;i++){
            int j = latestNonConflictJob(arr,i);
            int inclprofit = arr[i].profit;
            if(j!=-1){
                inclprofit+=dp[j];
            }
            dp[i] = max(dp[i-1], inclprofit);
        }
        
        return dp[n-1];
    }
};


TC: O(nlogn), sc: O(n);
logn bcoz we used binary search to find the latest non conflicting Job
Binary search could be used bcoz the jobs were sorted on the basis of finish time