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


Solution:

TC: O(nlogn), n unique calls & logn time for finding upperbound
SC: O(n) max depth of recursion tree is n hence O(n)
class Solution {
public:
    int t[370];
    int solve(int i,vector<int>& days, vector<int>& costs,int n){
        if(i>=n) return 0;
        if(t[i]!=-1) return t[i];
        
        int op1=costs[0]+solve(i+1,days,costs,n);
        
        int i1=upper_bound(days.begin(),days.end(),days[i]+6) - days.begin();
        int op2=costs[1]+solve(i1,days,costs,n);
        
        int i2=upper_bound(days.begin(),days.end(),days[i]+29) - days.begin();
        int op3=costs[2]+solve(i2,days,costs,n);
        
        return t[i] = min({op1,op2,op3});
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        int n=days.size();
        
        memset(t,-1,sizeof(t));
        
        return solve(0,days,costs,n);
    }
};