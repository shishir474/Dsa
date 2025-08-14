983. Minimum Cost For Tickets

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.


class Solution {
public:
    int t[370];
    int solve(int i, vector<int>& days, vector<int>& costs){
        if(i >= days.size()) return 0;
        if(t[i] != -1) return t[i];

        int option1 = costs[0] + solve(i+1, days, costs);

        int idx1 = lower_bound(days.begin(),days.end(),days[i]+7) - days.begin();
        int option2 = costs[1] + solve(idx1, days, costs);
        
        int idx2 = lower_bound(days.begin(),days.end(),days[i]+30) - days.begin();
        int option3 = costs[2] + solve(idx2, days, costs);

        return t[i] = min({option1, option2, option3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // sort days so that we can apply lower/upper bounds
        sort(days.begin(), days.end());
        memset(t,-1,sizeof(t));
        return solve(0, days, costs);
    }
};
// TC: O(nlogn) for sorting and O(n) unique recursive calls. For each call, we are doing O(logn) work to find the upper bound for 7-day and 30-day passes.
// SC: O(n) for the recursion stack space and the memoization array.


pattern:
standard dp problem to minimise the total cost.
