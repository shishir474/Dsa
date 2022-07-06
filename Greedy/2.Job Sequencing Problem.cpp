Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compare(Job j1, Job j2){
       return j1.profit > j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, compare); // sort on the basis of profit;
        int maxdead = INT_MIN;
        for (int i=0;i<n;i++){
            maxdead = max(maxdead, arr[i].dead);
        }
        int available[maxdead] = {0};
        int maxprofit = 0, count=0;
        for (int i=0;i<n;i++){
            int f=0;
            for (int j=arr[i].dead-1;j>=0;j--){
                if (available[j]==0){
                    available[j] = 1;
                    f=1;
                    break;
                }
            }
            
            if(f){
                maxprofit+=arr[i].profit;
                count++;
            }
        }
        
        vector<int> v;
        v.push_back(count);
        v.push_back(maxprofit);
        return v;
    } 
};


practise problems related to weighted job scheduling,activity selection,and job sequencing on leetcode