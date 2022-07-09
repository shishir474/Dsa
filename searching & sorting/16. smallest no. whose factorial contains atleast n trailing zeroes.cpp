Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.


class Solution
{
    public:
    // check if mid! has n trailing zeroes or not
        bool ispossible(int mid, int n){
            int p=5, cnt=0;
            while(p<=mid){
                cnt+=(mid/p);
                p*=5;
            }
            
            return cnt>=n;
        }
        
        int findNum(int n)
        {
            int ans=-1;
            int lo=1,hi=1e9;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(ispossible(mid, n)){
                    ans = mid;
                    hi = mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            
            return ans;
            
        }
};
