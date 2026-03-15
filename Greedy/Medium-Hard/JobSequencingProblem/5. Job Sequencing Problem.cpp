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


(2,80), (6, 70), (6, 65), (5, 60), (4, 25), (2,22), (4, 20), (2,10)

There can be 2 ways to look at this problem:

1. sort the jobs in decreasing order of profits, because we want to maximise the profit at the end of the day.
    and if 2 jobs have same profit, then we prioritise the job with earlier deadline first. This logic alone wont work. we also need to take into consideratino the slot in which we want to execute a particular job.

    first job: profit 80, deadline 2: I will perform this job in slot 2
    second job: profit 70, deadline 6: I will perform this job in slot 6
    third job: profit 65, deadline 6: I cannot perform this job in slot 6, can I perform it in slot 5? yes I can
    fourth job: profit 60, deadline 5: I cannot perform this job in slot 5, can I perform it in slot 4? yes I can
    fifth job: profit 25, deadline 4: I cannot perform this job in slot 4, can I perform it in slot 3? yes I can
    sixth job: profit 22, deadline 2: I cannot perform this job in slot 2, can I perform it in slot 1? yes I can
    seventh job: profit 20, deadline 4: I cannot perform this job in slot 4, can I perform it in slot 3? no I cannot, can I perform it in slot 2? no I cannot, can I perform it in slot 1? no I cannot
    eighth job: profit 10, deadline 2: I cannot perform this job in slot 2, can I perform it in slot 1? no I cannot 

    One thing is clear, for sure: We want to perform each jobs as close as possible to their deadline.
    This allows us more room to accomodate other jobs before it.
    

2. sort the jobs in increasing order of deadlines, so that jobs with earlier deadlines are prioritised first. This way we will be able to accomodate maximum no of jobs.
   maximising the no of jobs does not necessarily mean maximising the profit.



first approach is a good starting point. The real question is when do we want to schedule a job?
We want to schedule a job as close to its deadline as possible. SO that it allows room for other jobs to be accomodated before it.


One thing is for sure: we want to delay the execution of the job as much as possible, and perform it as close as possible to their deadline.
By doing this, we leave space for other jobs to be executed before it.

-- My idea : This will not work 
-- so if we sort the jobs in ascending order of their deadlines, so we can prioritze the jobs with earlier deadlines first and if the deadlines of 2 jobs are same, then we prioritize the job with higher profit first.

(2,80), (2,22), (2,10), (4, 25), (4, 20), (5, 60), (6, 70), (6, 65)
here you are giving more weightage to the jobs with earlier deadlines, but you are not considering the profit factor.

In the strivers approach, we are giviing weightage to the jobs that has higher profit and then we are trying to accomodate it as close to its deadline as possible. -- so both the conditions are being taken care of.

The whole idea is you want to maximise profit. So you prioritise the jobs with higher profit first and you try to perform them as close to their deadlines as possible.

-- strivers approach:
End goal is to maximise profit. and we want to delay the execution of the job as much as possible, and perform it as close as possible to their deadline.
I''ll sort the jobs in descending order of profit(because we want to maximise profit). 
I''ll also create a hash arr[max_deadline] which will keep track of which deadlines are already occupied.


id deadline profit 
6   2        80
3   6        70
4   6        65
2   5        60
5   4        25
8   2        22
1   4        20
7   2        10

0     1    2    3    4    5    6
-1   -1   -1   -1   -1   -1   -1

initialised with -1 -- indicates that the slot is free 
First job: deadline is 2 -- can I accomodate it at 2nd slot? Yes I can
profit = 80
0     1    2    3    4    5    6
-1   -1   6    -1   -1   -1   -1

Second job: deadline is 6 -- can I accomodate it at 6th slot? Yes I can
profit = 80 + 70 = 150
0     1    2    3    4    5    6
-1   -1   6    -1   -1   -1   3 
Third job: deadline is 6 -- can I accomodate it at 6th slot? No I cannot
can I accomodate it at 5th slot? Yes I can
profit = 80 + 70 + 65 = 215
0     1    2    3    4    5    6
-1   -1   6    -1   -1   4   3 
Fourth job: deadline is 5 -- can I accomodate it at 5th slot? No I cannot
can I accomodate it at 4th slot? Yes I can
profit = 80 + 70 + 65 + 60 = 275
0     1    2    3    4    5    6
-1   -1   6    -1   2   4   3



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
        int hash[maxdead+1] = {-1};
        int maxprofit = 0, count=0;
        for (int i = 0; i < n; i++){
            int f = 0;
            for (int j = arr[i].dead; j >= 1; j--){
                if (hash[j]==-1){
                    hash[j] = i;
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

TC: O(nlogn) + O(n * max_deadline)
SC: O(max_deadline)


-- Insane optimization techinque:   -- ** revisit DSU lecture of striver **

-- we can optimise the inner loop using Disjoint Set Union (DSU) or Union Find data structure.

dsu -- will help us to find the next available slot in O(1) time.

vector<int> dsu(max_deadline + 1);
for (int i = 0; i <= max_deadline; i++) dsu[i] = i;

auto find = [&](int x) {
    if (dsu[x] != x) dsu[x] = find(dsu[x]);
    return dsu[x];
};

for (int i = 0; i < n; i++) {
    int available_slot = find(arr[i].dead);
    if (available_slot > 0) {
        dsu[available_slot] = find(available_slot - 1);
        maxprofit += arr[i].profit;
        count++;
    }
}

TC: O(nlogn) + O(n)
SC: O(max_deadline)

practise problems related to weighted job scheduling,activity selection,and job sequencing on leetcode


***************************************************************************

NOTES: 
Each job has a deadline and profit associated. We need to find the max profit. 
Trick is: In order to acheive max profit -- we sort jobs in decreasing order of profits and try to assign them the slot closest to the deadline(atleast thats what we will try). If not we find the next best slot available.

finding best slot loop can be optimised to O(1) using DSUs 
DSU Optimisation 

***************************************************************************