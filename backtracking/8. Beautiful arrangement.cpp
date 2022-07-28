526. Beautiful Arrangement

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Brute force:
generate all permutaions & check if its valid or not
TC: o(n!)*n -> n! for genarating all permutaions and n for checking each permutation
SC: O(n) -> depth of recursion tree can be O(n) at max



Optimised solution:
TC: O(k!) where k is the number of valid permutaions
SC: O(n) depth of recursion tree can be O(n) at max

class Solution {
public:
    void solve(int idx,int& c,vector<int>& a,int n){
        if(idx==n){
            c++;
            return;
        }
        for(int i=idx;i<n;i++){ // idx-> 0 based hence + 1
            if(a[i]%(idx+1)==0 || (idx+1)%a[i]==0){
                swap(a[i],a[idx]);
                solve(idx+1,c,a,n);
                swap(a[i],a[idx]);
            }
        }
    }
    int countArrangement(int n) {
        int c=0;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i]=i+1;
        }
        solve(0,c,a,n);
        return c;
    }
};